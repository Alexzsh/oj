#pragma warning(disable:4786)
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <time.h>
#include <algorithm>
#include <numeric>  
#include <iostream>
//#include <string>
using namespace std;


// 歌手 结构体
struct Singer
{
	// 名字
	string strName;

	// 最新得分
	int iLatestScore;
};

// 歌唱比赛类
class CSingerCompetition
{
public:
	// 所有的参赛ID与歌手的映射集合,int：参赛ID，Singer：参加比赛的歌手
	map<int, Singer>  m_mapSinger;

	// 剩余歌手（没被淘汰的歌手）的参赛ID的集合, int:剩余歌手的参赛ID
	list<int>  m_lstRemainingID;

	// 当前演唱小组的歌手分数与歌手参赛ID的映射集合。参赛分别为：歌手分数、歌手参赛ID、用于歌手分数的降序排列
	multimap<int, int, greater<int> >  m_mltmapCurGroup;

	// 第一轮淘汰赛中被淘汰的歌手名字的集合,int为歌手的参赛号
	vector<int>  m_vecIDBeEliminatedInFirstRound;

	// 第二轮淘汰赛中被淘汰的歌手分数的集合,int代表歌手分数
	multiset<int>  m_mltsetScoreBeEliminatedInSecondRound;



	// 第几轮比赛
	int m_iRound;

public:
	CSingerCompetition();
	~CSingerCompetition() {};

public:
	
	// 淘汰赛规则
	void Knockout();

	// 得分
	void MakeScore(Singer &singer);

	// 打印当前小组分数
	void PrintGroupScore();

	// 在当前小组中淘汰歌手
	void EraseInCurGroup();

	// 在剩余歌手中删除歌手
	void EraseRemainingID(list<int>::iterator it);


public:
	// 报名参加比赛
	void JoinCompetition();


	// 第一轮淘汰赛
	void FirstKnockout();

	// 第二轮淘汰赛
	void SecondKnockout();

	// 决赛
	void Finals();
};

// 歌手比赛的构造函数
CSingerCompetition::CSingerCompetition()
{
	// 还没开始比赛，比赛轮数设置为0
	m_iRound = 0;

	// 设置随机种子
	srand((unsigned)time(0));
}


// 报名参加比赛
void CSingerCompetition::JoinCompetition()
{
	// 名字组成元素的来源
	string strNameBaseSource("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	// 随机排序名字组成元素的来源
	random_shuffle(strNameBaseSource.begin(), strNameBaseSource.end());

	for (int i=0; i<24; i++)
	{
		// 获取参加比赛的歌手名字
		string strExt(1, strNameBaseSource[i]);

		// 构造歌手对象
		Singer  singer;
		singer.iLatestScore = 0;
		singer.strName = "选手";
		singer.strName += strExt;

		// 录入参加比赛的歌手
		m_mapSinger.insert(pair<int, Singer>(i+100, singer));
		m_lstRemainingID.push_back(i+100);
	}
	
	// 打印参加比赛的歌手名字与参赛号
	cout <<"****************************************************************" << endl;
	cout << "参加比赛的歌手名字与参赛号：" << endl << endl;
	for (map<int, Singer>::iterator  it=m_mapSinger.begin();
		it!=m_mapSinger.end(); ++it)
	{
		//TRACE("%s, 参赛号：%d\n", it->second.strName.c_str(), it->first);
		cout << it->second.strName.c_str() << "  参赛号" << it->first;
		cout << endl;
	}
}


// 淘汰赛规则
void CSingerCompetition::Knockout()
{
	cout << "*************************第"<<m_iRound <<"轮淘汰赛*****************************" << endl;
	// 第几个歌手正在演唱
	int iSingerIndex = 0;
	for (list<int>::iterator  it=m_lstRemainingID.begin(); it!=m_lstRemainingID.end(); )
	{
		++iSingerIndex;

		// 生成歌手的分数
		MakeScore(m_mapSinger[*it]);

		// 记录当前演唱小组歌手的得分情况，按分数降序排列
		m_mltmapCurGroup.insert(pair<int, int>(m_mapSinger[*it].iLatestScore, *it));

		if (iSingerIndex % 6 == 0)
		{
			// 小组演唱完毕，打印小组得分
			PrintGroupScore();

			// 在当前小组中淘汰歌手
			EraseInCurGroup();

			// 在剩余歌手中删除歌手
			EraseRemainingID(it++);  //不可用++it代替，因为要转入自增之前的迭代器
		}
		else
		{
			++it;
		}
	}
}


// 裁判打分
void CSingerCompetition::MakeScore(Singer &singer)
{
	// 存放裁判给的分数
	deque<int>  deqScore;

	// 是个评委分别给歌手打分，打分过程没要求排序
	for (int i=0; i<10; ++i)
	{
		int iScore = 60 + rand() % 40;
		deqScore.push_back(iScore);
	}

	// 为评委打分排序
	sort(deqScore.begin(), deqScore.end());

	// 去掉最高分，去掉最低分
	deqScore.pop_front();
	deqScore.pop_back();
	
	// 求8个评委打分总和
	int iScoreSum = accumulate(deqScore.begin(), deqScore.end(), 0);

	// 求八个评委的平均分
	int iScoreAverage = (int) (iScoreSum/deqScore.size());

	// 给歌手设置得分
	singer.iLatestScore = iScoreAverage;
}



// 打印当前小组
void CSingerCompetition::PrintGroupScore()
{
	cout << "小组得分情况：" << endl;
	multimap<int, int, greater<int> >::iterator  it,iend;
	it = m_mltmapCurGroup.begin();
	iend = m_mltmapCurGroup.end();
	for ( it; it!=iend; ++it)
	{
		cout << m_mapSinger[it->second].strName.c_str() 
			 << " 的得分：" 
			 << it->first 
			 << endl; 
	}
	cout << endl;
}


// 在当前小组中淘汰歌手
void CSingerCompetition::EraseInCurGroup()
{
	// 组内歌手的倒数索引
	int iSingerLastIndexInGroup = 0;

	while (iSingerLastIndexInGroup < 3)
	{
		// 获取当前演唱小组的最后一个元素的迭代器
		multimap<int, int, greater<int> >::iterator  it = m_mltmapCurGroup.end();
		--it;

		++iSingerLastIndexInGroup;

		if (m_iRound == 1)
		{
			// 记录第一轮淘汰赛中被淘汰的歌手的参赛号
			m_vecIDBeEliminatedInFirstRound.push_back(it->second);
		}
		else if (m_iRound == 2)
		{
			//记录第二轮淘汰赛中被淘汰的歌手的分数
			m_mltsetScoreBeEliminatedInSecondRound.insert(m_mapSinger[it->second].iLatestScore);
		}

		// 从当前演唱小组的集合容器中删除最后一个元素
		m_mltmapCurGroup.erase(it);
	}
}




// 在剩余歌手中删除歌手
void CSingerCompetition::EraseRemainingID(list<int>::iterator it)
{
	// 逆向遍历的索引
	int iSingerReverseIndexInGroup = 0;

	while (iSingerReverseIndexInGroup<6)
	{
		//查找逆向遍历迭代器所指的参赛ID所对应歌手的{分数，参赛ID}是否在当前演唱小组中
		multimap<int, int, greater<int> >::iterator  itMltmapScoreToID;
		itMltmapScoreToID = find(m_mltmapCurGroup.begin(), m_mltmapCurGroup.end(), 
			multimap<int, int, greater<int> >::value_type(m_mapSinger[*it].iLatestScore, *it));

		if (itMltmapScoreToID == m_mltmapCurGroup.end())
		{
			// 没找到，从剩余歌手集合中删除该歌手的参赛号
			it = m_lstRemainingID.erase(it);
		}

		// 逆向遍历的索引自增
		++iSingerReverseIndexInGroup;

		// 防止对容器的begin() 迭代器进行操作
		if (it != m_lstRemainingID.begin())
		{
			--it;
		}
	}

	// 清除该组的比赛记录存储，以便下一组比赛记录的存储
	m_mltmapCurGroup.clear();
}






// 第一轮淘汰赛
void CSingerCompetition::FirstKnockout()
{
	if (m_iRound == 0)
	{
		m_iRound = 1;
		
		// 进行淘汰赛
		Knockout();
		
		//TRACE("第%d轮淘汰赛中被淘汰的歌手的名字：\n", m_iRound);
		cout << "第1轮淘汰赛中被淘汰的歌手的名字：" << endl;
		
		for (vector<int>::iterator  it=m_vecIDBeEliminatedInFirstRound.begin();
			it!=m_vecIDBeEliminatedInFirstRound.end(); ++it)
		{
			//TRACE("%s", m_mapSinger[*it].strName.c_str());
			cout << m_mapSinger[*it].strName.c_str() << "  ";
		}
		
		cout << endl << endl;
	}
}






// 第二轮淘汰赛
void CSingerCompetition::SecondKnockout()
{
	if(m_iRound == 1)
	{
		m_iRound = 2;

		// 进行淘汰赛
		Knockout();
		cout << "第2轮淘汰赛中被淘汰的歌手的分数：" << endl;
		
		multiset<int>::iterator  it, iend;
		it = m_mltsetScoreBeEliminatedInSecondRound.begin();
		iend = m_mltsetScoreBeEliminatedInSecondRound.end();
		for (it; it!=iend; ++it)
		{
			cout << *it << "  ";
		}
		cout << endl << endl;
	}
}




// 决赛
void CSingerCompetition::Finals()
{
	if (m_iRound == 2)
	{
		m_iRound = 3;

		// 第三轮决赛
		for (list<int>::iterator  it=m_lstRemainingID.begin(); it!=m_lstRemainingID.end(); ++it)
		{
			// 生成歌手分数
			MakeScore(m_mapSinger[*it]);

			// 记录当前小组歌手得分情况，按分数降序排列
			m_mltmapCurGroup.insert(pair<int, int>(m_mapSinger[*it].iLatestScore, *it));

		}

		// 打印小组决赛情况
		cout << "****************************小组决赛情况：*****************************" << endl;

		multimap<int, int, greater<int> >::iterator  mit, iend;
		mit = m_mltmapCurGroup.begin();
		iend = m_mltmapCurGroup.end();
		for (mit; mit!=iend; ++mit)
		{
			cout << m_mapSinger[mit->second].strName.c_str()
				 << " 的得分："
				 << mit->first
				 << endl;
		}
		cout << endl << endl;

		// 清除所有的数据
		m_mapSinger.clear();
		m_lstRemainingID.clear();
		m_vecIDBeEliminatedInFirstRound.clear();
		m_mltsetScoreBeEliminatedInSecondRound.clear();
		m_mltmapCurGroup.clear();
		m_iRound = 0;
	}
}








int main(int argc, char* argv[])
{


	// 定义比赛的对象
	CSingerCompetition singerCompetition;

	// 参赛选手报名 
	singerCompetition.JoinCompetition();

	// 第一轮淘汰赛
	singerCompetition.FirstKnockout();

	// 第二轮淘汰赛
	singerCompetition.SecondKnockout();

	// 决赛
	singerCompetition.Finals();


	return 0;
}

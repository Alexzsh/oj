def func(coin_values,money):
    coins=[0]*(money+1)
    coins[0]=0
    for cents in range(1,money+1):
        min_coins = cents
        for every_coin in range(len(coin_values)):
            if coin_values[every_coin]<=cents:
                temp = coins[cents-coin_values[every_coin]]+1
                if temp<min_coins:
                    min_coins=temp
        coins[cents]=min_coins
    return coins[money]
money = int(input())
print(func([1,4,16,64],1024-money))
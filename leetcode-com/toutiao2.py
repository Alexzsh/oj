def reverseVowels(s):
    left = 0
    right = len(s)-1
    s = list(s)
    while left < right:
        while left < right and s[left] not in 'aeiou':
            left += 1
        while left < right and s[right] not in 'aeiou':
            right -= 1
        if left < right:
            s[left], s[right] = s[right], s[left]
    return ''.join(s)


reverseVowels('aA')

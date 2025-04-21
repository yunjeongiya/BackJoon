def solution(N, number):
    if N == number: return 1
    
    cases = {i: {int(str(N)*i)} for i in range(1,9)}
    
    for i in range(1,9):
        for j in range(1, i):  # 수정된 부분 (i+1 → i)
            for a in cases[j]:
                for b in cases[i-j]:
                    cases[i].update({a+b, a-b, a*b})
                    if b !=0: cases[i].add(a//b)
                    if a !=0: cases[i].add(b//a)
        if number in cases[i]: return i
    return -1
def solution(numbers):
    result = "".join(map(str, sorted(map(num, numbers), reverse=True)))
    return "0" if result[0] == "0" else result

'''
3 vs 30 -> 3 / 30 vs 34 -> 34 / 3 vs 34 -> 34
아 정렬함수를 그냥 직접 둘씩 붙여보게 하면 되겠다
'''

class num:
    def __init__(self, val):
        self.val = val
    
    def __eq__(self, other): 
        #이거 없으면 print(num(1)==num(1)) -> False
        #근데 이거 때문에 틀린 줄 알았는데 아니네...
        return self.val == other.val
    
    def __lt__(self, other):
        return str(self)+str(other) < str(other)+str(self)
    
    def __str__(self):
        return str(self.val)
    
    
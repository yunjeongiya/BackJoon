def solution(triangle):
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            v1, v2 = 0, 0
            if 0 < j:
                v1 = triangle[i][j] + triangle[i-1][j-1]
            if j < len(triangle[i-1]):
                v2 = triangle[i][j] + triangle[i-1][j] #TS j+1 이 아니라 j
            triangle[i][j] = max(triangle[i][j], v1, v2)
    #print(triangle)
    return max(triangle[-1])
            
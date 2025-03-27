def solution(sizes):
    wMax = 0
    hMax = 0
    for w, h in sizes:
        if w < h:
            w, h = h, w
        if wMax < w:
            wMax = w
        if hMax < h:
            hMax = h
    return wMax * hMax
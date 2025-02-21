SELECT ID, FISH_NAME, LENGTH
FROM FISH_INFO as f JOIN FISH_NAME_INFO as n
    ON f.FISH_TYPE = n.FISH_TYPE
WHERE (f.FISH_TYPE, LENGTH) IN 
( SELECT FISH_TYPE, MAX(LENGTH) as LENGTH FROM FISH_INFO GROUP BY FISH_TYPE )
ORDER BY ID
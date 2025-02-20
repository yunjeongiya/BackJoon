-- 코드를 작성해주세요
SELECT ROUND(AVG(
    CASE 
        WHEN LENGTH is null THEN 10
        ELSE LENGTH
    END),
             2) as AVERAGE_LENGTH
FROM FISH_INFO
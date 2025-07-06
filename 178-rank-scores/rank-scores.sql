# Write your MySQL query statement below
-- select score, dense_rank() over (order by Score  desc) 'Rank'
-- From Scores

-- order by score desc;
select s1.score, 
                            (select count(distinct s2.score)
                            from scores as s2
                            where s2.score>=s1.score)as 'Rank'
From scores as s1
order by s1.score desc;
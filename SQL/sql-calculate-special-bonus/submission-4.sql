-- Write your query below
-- an employee receives a bonus equal to 100% of salary
-- if employee_id%2!=0 and name not like 'M%' bonus=salary
-- else bonus=0

SELECT employee_id,
CASE 
    WHEN employee_id % 2 != 0 AND name NOT LIKE 'M%' 
        THEN salary
    ELSE 0
END AS bonus
FROM employees
order by employee_id;

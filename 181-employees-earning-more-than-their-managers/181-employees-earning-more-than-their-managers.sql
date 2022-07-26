# Write your MySQL query statement below
SELECT E1.name as Employee
FROM Employee AS E1,Employee AS E2
WHERE E1.managerId=E2.id AND E1.salary>E2.salary;

# select E1.Name as Employee
# from Employee as E1, Employee as E2 
# where E1.ManagerId = E2.Id and E1.Salary > E2.Salary;

# select e.Name as Employee
# from Employee e, Employee m
# where e.ManagerId is not NULL and
# e.ManagerId = m.ID and e.Salary > m.Salary
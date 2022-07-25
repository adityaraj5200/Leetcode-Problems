# Write your MySQL query statement below
SELECT p.firstName,p.lastName,a.city,a.state
FROM Person AS p LEFT JOIN Address AS a ON p.personId = a.personId;


# SELECT Person.FirstName, Person.LastName, Address.City, Address.State from Person LEFT JOIN Address on Person.PersonId = Address.PersonId;

# select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId;

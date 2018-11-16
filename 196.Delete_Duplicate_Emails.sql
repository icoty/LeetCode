+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Id is the primary key column for this table.

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+



# Write your MySQL query statement below

DELETE p2 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p2.Id > p1.Id;

#if 0
DELETE FROM Person WHERE Id NOT IN 
(SELECT Id FROM (SELECT MIN(Id) Id FROM Person GROUP BY Email) p);


DELETE p2 FROM Person p1 JOIN Person p2 
ON p2.Email = p1.Email WHERE p2.Id > p1.Id;
#endif


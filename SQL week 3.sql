CREATE DATABASE internship_db;
USE internship_db;

CREATE TABLE student(
stu_id INT PRIMARY KEY,
name VARCHAR(50),
dept VARCHAR(50),
age INT);

INSERT INTO student(stu_id, name, dept, age)
VALUES
(101, 'Ali', 'CS', 24),
(102, 'Saman', 'AI', 23),
(103, 'Saad', 'CS', 22),
(104, 'Zara', 'CS', 22),
(105, 'Amna', 'AI', 22);

CREATE TABLE stu_marks(
stu_id INT PRIMARY KEY,
name VARCHAR(50),
eng INT,
math INT,
CS INT);

INSERT INTO stu_marks(stu_id, name, eng, math, CS)
VALUES
(101, 'Ali', 92, 80, 82),
(102, 'Saman', 89, 78, 90),
(103, 'Saad', 90, 80, 75),
(104, 'Zara', 75, 73, 85),
(105, 'Amna', 80, 81, 94);

SELECT * FROM stu_marks;

SELECT COUNT(stu_id)
FROM stu_marks;

SELECT SUM(eng)
FROM stu_marks;

SELECT name, AVG(eng+math+CS)/3 AS avg_marks
FROM stu_marks
GROUP BY name;

SELECT MAX(eng)
FROM stu_marks;

SELECT MIN(math)
FROM stu_marks;

SELECT name, AVG(eng+math+CS)/3 AS avg_marks
FROM stu_marks
GROUP BY name
HAVING avg_marks>80;

SELECT * FROM student as s
INNER JOIN stu_marks as m
ON s.stu_id = m.stu_id;
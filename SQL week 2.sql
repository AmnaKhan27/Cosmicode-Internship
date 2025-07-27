CREATE DATABASE internship_db;
USE internship_db;

CREATE TABLE student(
stu_id INT PRIMARY KEY,
name VARCHAR(50),
dept VARCHAR(50),
age INT);

INSERT INTO student
(stu_id, name, dept, age)
VALUES
(101, 'Ali', 'CS', 24),
(102, 'Alishba', 'CS', 23),
(103, 'Saad', 'AI', 23),
(104, 'Hamza', 'CS', 22),
(105, 'Sana', 'AI', 24);

SELECT * FROM student;

UPDATE student
SET age = 19
WHERE stu_id = 103;

DELETE FROM student
WHERE stu_id = 105;

SELECT * FROM student 
WHERE age>20;

SELECT * FROM student 
ORDER BY name, age ASC;

SELECT * FROM student
WHERE age BETWEEN 18 AND 22;

SELECT * FROM student
WHERE age IN(23,24);

SELECT * FROM student
WHERE name LIKE 'A%';

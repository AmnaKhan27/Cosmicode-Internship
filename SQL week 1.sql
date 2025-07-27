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
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
eng INT NOT NULL,
math INT NOT NULL,
CS INT NOT NULL);

INSERT INTO stu_marks(stu_id, name, eng, math, CS)
VALUES
(101, 'Ali', 92, 80, 82),
(102, 'Saman', 89, 78, 90),
(103, 'Saad', 90, 80, 75),
(104, 'Zara', 75, 73, 85),
(105, 'Amna', 80, 81, 94);

CREATE TABLE courses(
c_id INT PRIMARY KEY,
c_name VARCHAR(50),
credit_hr INT
);

INSERT INTO courses(c_id, c_name, credit_hr)
VALUES
(001, 'english', 3),
(002, 'math', 4),
(003, 'CS', 4);

CREATE TABLE enrollment(
enrol_id INT PRIMARY KEY,
enrol_date INT,
stu_id INT,
c_id INT, 
FOREIGN KEY (stu_id) REFERENCES student(stu_id),
FOREIGN KEY (c_id) REFERENCES courses(c_id)
);

INSERT INTO enrollment(enrol_id, enrol_date, stu_id, c_id)
VALUES
(0011, 2/7/23, 101, 001),
(0022, 4/5/23, 102, 002),
(0033, 7/7/23, 103, 002);

CREATE VIEW temp AS
SELECT name, AVG(eng+math+CS)/3 AS avg_marks
FROM stu_marks
GROUP BY name;
     
SELECT * FROM temp;

START TRANSACTION;

UPDATE stu_marks 
SET eng=79 WHERE stu_id = 103;

COMMIT;

START TRANSACTION;

INSERT INTO student(stu_id, name, dept, age)
VALUES
(106, 'Sufyan', 'math', 23);

ROLLBACK;

TRUNCATE sudent;
TRUNCATE stu_marks;
TRUNCATE enrollment;
TRUNCATE couses;
TRUNCATE temp;

DROP TABLE sudent;
DROP TABLE stu_marks;
DROP TABLE enrollment;
DROP TABLE couses;
DROP VIEW temp;






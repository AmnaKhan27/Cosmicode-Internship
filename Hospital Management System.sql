CREATE DATABASE HospitalManagementSystem;
USE HospitalManagementSystem;

CREATE TABLE Admin (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    password VARCHAR(100) NOT NULL,
    phone VARCHAR(15)
);

CREATE TABLE Doctors (
    doc_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    specialization VARCHAR(50) NOT NULL,
    phone VARCHAR(15),
    email VARCHAR(100) UNIQUE
);

CREATE TABLE Nurses (
    nurse_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    phone VARCHAR(15),
    email VARCHAR(100) UNIQUE,
    ward VARCHAR(50)
);

CREATE TABLE Staff (
    staff_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    role VARCHAR(50) NOT NULL,
    phone VARCHAR(15),
    email VARCHAR(100) UNIQUE
);

CREATE TABLE Room (
    room_id INT PRIMARY KEY AUTO_INCREMENT,
    room_type VARCHAR(50) NOT NULL,
    ward VARCHAR(50) NOT NULL,
    capacity INT NOT NULL
);

CREATE TABLE Inpatient (
    inpatient_id INT PRIMARY KEY AUTO_INCREMENT,
    patient_name VARCHAR(50) NOT NULL,
    gender VARCHAR(10),
    age INT,
    address VARCHAR(200),
    phone VARCHAR(15),
    admission_date DATE NOT NULL,
    discharge_date DATE,
    room_id INT,
    doc_id INT,
    FOREIGN KEY (room_id) REFERENCES Room(room_id),
    FOREIGN KEY (doc_id) REFERENCES Doctors(doc_id)
);

CREATE TABLE Outpatient (
    outpatient_id INT PRIMARY KEY AUTO_INCREMENT,
    patient_name VARCHAR(50) NOT NULL,
    gender VARCHAR(10),
    age INT,
    address VARCHAR(200),
    phone VARCHAR(15),
    registration_date DATE NOT NULL,
    doc_id INT,
    FOREIGN KEY (doc_id) REFERENCES Doctors(doc_id)
);

CREATE TABLE InpatientBill (
    bill_id INT PRIMARY KEY AUTO_INCREMENT,
    inpatient_id INT NOT NULL,
    total_amount DECIMAL(10,2) NOT NULL,
    bill_date DATE NOT NULL,
    FOREIGN KEY (inpatient_id) REFERENCES Inpatient(inpatient_id)
);

CREATE TABLE OutpatientBill (
    bill_id INT PRIMARY KEY AUTO_INCREMENT,
    outpatient_id INT NOT NULL,
    total_amount DECIMAL(10,2) NOT NULL,
    bill_date DATE NOT NULL,
    FOREIGN KEY (outpatient_id) REFERENCES Outpatient(outpatient_id)
);

CREATE TABLE Cashier (
    cashier_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    phone VARCHAR(15),
    email VARCHAR(100) UNIQUE
);

INSERT INTO Admin (name, email, password, phone) VALUES
('Ali Raza', 'ali.raza@hospital.com', 'secure123', '03001234567'),
('Fatima Khan', 'fatima.khan@hospital.com', 'admin456', '03111234567'),
('Ahmed Malik', 'ahmed.malik@hospital.com', 'pass789', '03211234567'),
('Ayesha Siddiqui', 'ayesha.siddiqui@hospital.com', 'ayesha123', '03331234567'),
('Bilal Hassan', 'bilal.hassan@hospital.com', 'bilalpass', '03451234567'),
('Sana Akhtar', 'sana.akhtar@hospital.com', 'sana456', '03051234567'),
('Usman Sheikh', 'usman.sheikh@hospital.com', 'usmanpass', '03121234567'),
('Hina Aslam', 'hina.aslam@hospital.com', 'hina789', '03221234567'),
('Kamran Iqbal', 'kamran.iqbal@hospital.com', 'kamran123', '03301234567'),
('Zainab Abbas', 'zainab.abbas@hospital.com', 'zainab456', '03401234567');

INSERT INTO Doctors (name, specialization, phone, email) VALUES
('Dr. Usman Ali', 'Cardiology', '03001234561', 'usman.ali@hospital.com'),
('Dr. Ayesha Khan', 'Pediatrics', '03111234562', 'ayesha.khan@hospital.com'),
('Dr. Farhan Ahmed', 'Neurology', '03211234563', 'farhan.ahmed@hospital.com'),
('Dr. Saima Riaz', 'Gynecology', '03331234564', 'saima.riaz@hospital.com'),
('Dr. Omar Sheikh', 'Orthopedics', '03451234565', 'omar.sheikh@hospital.com'),
('Dr. Zara Malik', 'Dermatology', '03051234566', 'zara.malik@hospital.com'),
('Dr. Imran Hassan', 'General Surgery', '03121234567', 'imran.hassan@hospital.com'),
('Dr. Nida Abbas', 'Ophthalmology', '03221234568', 'nida.abbas@hospital.com'),
('Dr. Tariq Iqbal', 'ENT', '03301234569', 'tariq.iqbal@hospital.com'),
('Dr. Hina Farooq', 'Psychiatry', '03401234560', 'hina.farooq@hospital.com');

INSERT INTO Nurses (name, phone, email, ward) VALUES
('Nurse Sarah Khan', '03011234561', 'sarah.khan@hospital.com', 'Pediatrics'),
('Nurse Ahmed Raza', '03121234562', 'ahmed.raza@hospital.com', 'ICU'),
('Nurse Fatima Malik', '03231234563', 'fatima.malik@hospital.com', 'Maternity'),
('Nurse Bilal Hassan', '03341234564', 'bilal.hassan@hospital.com', 'Cardiology'),
('Nurse Ayesha Siddiqui', '03451234565', 'ayesha.siddiqui@hospital.com', 'Emergency'),
('Nurse Usman Sheikh', '03061234566', 'usman.sheikh@hospital.com', 'Orthopedics'),
('Nurse Hina Aslam', '03171234567', 'hina.aslam@hospital.com', 'Neurology'),
('Nurse Kamran Iqbal', '03281234568', 'kamran.iqbal@hospital.com', 'General Ward'),
('Nurse Zainab Abbas', '03391234569', 'zainab.abbas@hospital.com', 'Pediatrics'),
('Nurse Omar Farooq', '03401234560', 'omar.farooq@hospital.com', 'ICU');

INSERT INTO Staff (name, role, phone, email) VALUES
('Asif Ali', 'Receptionist', '03012234561', 'asif.ali@hospital.com'),
('Sadia Khan', 'Accountant', '03123234562', 'sadia.khan@hospital.com'),
('Rizwan Ahmed', 'Lab Technician', '03234234563', 'rizwan.ahmed@hospital.com'),
('Nadia Riaz', 'Pharmacist', '03345234564', 'nadia.riaz@hospital.com'),
('Faisal Sheikh', 'Security Head', '03456234565', 'faisal.sheikh@hospital.com'),
('Tahira Malik', 'HR Assistant', '03067234566', 'tahira.malik@hospital.com'),
('Kamran Hassan', 'IT Support', '03178234567', 'kamran.hassan@hospital.com'),
('Nida Abbas', 'Cleaner Supervisor', '03289234568', 'nida.abbas@hospital.com'),
('Tariq Iqbal', 'Store Keeper', '03390234569', 'tariq.iqbal@hospital.com'),
('Hina Farooq', 'Cafeteria Manager', '03401234560', 'hina.farooq@hospital.com');

INSERT INTO Room (room_id, room_type, ward, capacity) VALUES
(1,'General', 'General Ward', 4),
(2,'General', 'General Ward', 4),
(3,'Semi-Private', 'Cardiology', 2),
(4,'Private', 'Pediatrics', 1),
(5,'ICU', 'Emergency', 1),
(6,'Private', 'Maternity', 1),
(7,'Semi-Private', 'Orthopedics', 2 ),
(8,'General', 'Neurology', 3),
(9,'Private', 'Gynecology', 1),
(10,'ICU', 'Cardiology',3);

INSERT INTO Inpatient (patient_name, gender, age, address, phone, admission_date, room_id, doc_id) VALUES
('Abdul Rehman', 'Male', 45, 'House 12, Street 7, Lahore', '03001234571', '2023-05-10', 1, 101),
('Fatima Bibi', 'Female', 32, 'Flat 5, Block C, Karachi', '03111234572', '2023-05-12', 4, 102),
('Ahmed Khan', 'Male', 28, 'House 23, G-9/1, Islamabad', '03211234573', '2023-05-15', 3, 103),
('Sadia Malik', 'Female', 56, 'Street 8, Phase 3, Rawalpindi', '03331234574', '2023-05-18', 6, 104),
('Bilal Hassan', 'Male', 40, 'House 34, Gulberg, Lahore', '03451234575', '2023-05-20', 5, 105),
('Zara Khan', 'Female', 25, 'Flat 12, Clifton, Karachi', '03051234576', '2023-05-22', 7, 106),
('Usman Sheikh', 'Male', 60, 'House 9, Street 15, Peshawar', '03121234577', '2023-05-25', 8, 107),
('Hina Aslam', 'Female', 35, 'Street 6, Satellite Town, Rawalpindi', '03221234578', '2023-05-28', 9, 108),
('Kamran Iqbal', 'Male', 50, 'House 45, F-11, Islamabad', '03301234579', '2023-05-30', 2, 109),
('Zainab Abbas', 'Female', 42, 'Flat 6, DHA Phase 6, Karachi', '03401234570', '2023-06-01', 10, 110);

INSERT INTO Outpatient (patient_name, gender, age, address, phone, registration_date, doc_id) VALUES
('Ali Raza', 'Male', 30, 'House 10, Street 5, Lahore', '03001234581', '2023-06-05', 101),
('Ayesha Khan', 'Female', 25, 'Flat 3, Block B, Karachi', '03111234582', '2023-06-06', 102),
('Farhan Ahmed', 'Male', 40, 'House 45, G-8/3, Islamabad', '03211234583', '2023-06-07', 103),
('Saima Riaz', 'Female', 35, 'Street 7, Phase 2, Rawalpindi', '03331234584', '2023-06-08', 104),
('Omar Sheikh', 'Male', 28, 'House 23, Gulberg, Lahore', '03451234585', '2023-06-09', 105),
('Zara Malik', 'Female', 22, 'Flat 10, Clifton, Karachi', '03051234586', '2023-06-10', 106),
('Imran Hassan', 'Male', 45, 'House 8, Street 14, Peshawar', '03121234587', '2023-06-11', 107),
('Nida Abbas', 'Female', 50, 'Street 5, Satellite Town, Rawalpindi', '03221234588', '2023-06-12', 108),
('Tariq Iqbal', 'Male', 38, 'House 34, F-10, Islamabad', '03301234589', '2023-06-13', 109),
('Hina Farooq', 'Female', 29, 'Flat 5, DHA Phase 5, Karachi', '03401234580', '2023-06-14', 110);

INSERT INTO InpatientBill (bill_id, inpatient_id, total_amount, bill_date) VALUES
(101, 1, 36000, '2023-05-15' ),
(102, 2, 36000, '2023-05-17' ),
(103, 3, 43000,'2023-05-20'),
(104, 4, 39000, '2023-05-23'),
(105, 5, 69000, '2023-05-25'),
(106,6, 37500,'2023-05-27'),
(107,7, 48000,'2023-05-30'),
(108, 8, 35000,'2023-06-02'),
(109, 9, 24000, '2023-06-04'),
(110, 10, 85000, 50000,'2023-06-06');

INSERT INTO OutpatientBill (bill_id, outpatient_id,total_amount, bill_date) VALUES
(1, 20, 9500,'2023-06-05'),
(2, 21, 5000, '2023-06-06'),
(3, 22,  11800, '2023-06-07'),
(4, 23,10600, '2023-06-08'),
(5, 24,  8700,'2023-06-09'),
(6, 25 , 9500,  '2023-06-10'),
(7, 26 ,13500, '2023-06-11'),
(8, 27,  10700, '2023-06-12'),
(9, 28, 8900, '2023-06-13'),
(10, 29, 10000, '2023-06-14');

INSERT INTO Cashier (name, phone, email) VALUES
('Raza Khan', '03001234591', 'raza.khan@hospital.com'),
('Sana Ahmed', '03111234592', 'sana.ahmed@hospital.com'),
('Farhan Malik', '03211234593', 'farhan.malik@hospital.com'),
('Ayesha Riaz', '03331234594', 'ayesha.riaz@hospital.com'),
('Omar Sheikh', '03451234595', 'omar.sheikh@hospital.com'),
('Zara Hassan', '03051234596', 'zara.hassan@hospital.com'),
('Imran Abbas', '03121234597', 'imran.abbas@hospital.com'),
('Nida Iqbal', '03221234598', 'nida.iqbal@hospital.com'),
('Tariq Farooq', '03301234599', 'tariq.farooq@hospital.com'),
('Hina Kamran', '03401234590', 'hina.kamran@hospital.com');

SELECT * FROM Doctors 
WHERE specialization = 'Cardiology' AND is_available = TRUE;

SELECT i.patient_name, d.name AS doctor_name, d.specialization
FROM Inpatient i
JOIN Doctors d ON i.doc_id = d.doc_id;

SELECT SUM(total_amount) AS total_revenue FROM InpatientBill;

SELECT b.bill_id, o.patient_name, b.total_amount, b.balance
FROM OutpatientBill b
JOIN Outpatient o ON b.outpatient_id = o.outpatient_id
WHERE b.status = 'Partial' OR b.status = 'Unpaid';

SELECT room_id, room_type, ward, 
       CASE WHEN is_available THEN 'Available' ELSE 'Occupied' END AS status
FROM Room;

SELECT * FROM Nurses WHERE ward = 'Pediatrics';

SELECT role, AVG(salary) AS average_salary
FROM Staff
GROUP BY role;

SELECT patient_name, admission_date, room_id
FROM Inpatient
WHERE admission_date >= DATE_SUB(CURDATE(), INTERVAL 30 DAY);
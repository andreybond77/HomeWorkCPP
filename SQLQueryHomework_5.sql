
--1
create table Departments_3(
Id int identity primary key NOT NULL
,Financing money CHECK(Financing >0) not null
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
,FacultyId int not null
,foreign key (FacultyId) references Departments_1(Id) 
);
--2
create table Faculties_3(
Id int identity primary key NOT NULL
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);
--3
create table Groups_3(
Id int identity primary key NOT NULL
, Name nvarchar(10) CHECK(Name > '') UNIQUE NOT NULL
,Year int  CHECK( Year>=1 AND Year<=5)NOT NULL
,DepartmentId int not null foreign key (DepartmentId) references Groups_3(Id)
);

--4
create table GroupsLectures_3(
Id int identity primary key NOT NULL
,GroupId int not null foreign key (Groupid) references GroupsLectures_3(Id)
,LecturesId int not null foreign key (LecturesId) references GroupsLectures_3(Id)
);

--5
create table Lectures_3(
Id int identity primary key NOT NULL
,DayOfWeek int CHECK(DayOfWeek >=1 AND DayOfWeek <=7) NOT NULL
,LectureRoom nvarchar(max) CHECK(LectureRoom > '') NOT NULL
,SubjectId int NOT NULL foreign key (SubjectId) references Lectures_3(Id)
,TeachersId int NOT NULL foreign key (TeachersId) references Lectures_3(Id)
);

--6
create table Subjects_3 (
Id int identity primary key NOT NULL
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);

--11
create table Teachers_3(
 Id int identity primary key NOT NULL
 , Name nvarchar(max) CHECK(Name > '') NOT NULL
 ,Salary money CHECK(Salary>0) NOT NULL
 ,Surname nvarchar(max) CHECK(Surname > '')NOT NULL
 );

insert into Departments_3(Id,Financing,Name,FacultyId)
values(1,1200,'Software Development',1);

insert into Faculties_3(Id,Name)
values (1,'Credit');

insert into Groups_3 (Id,Name,Year,DepartmentId)
values(1,'A-27',3,4);


insert into GroupsLectures_3(ID,GroupId,LecturesId)
values(1,4,3);

 
 insert into Lectures_3(Id,DayOfWeek,LectureRoom,SubjectId,TeachersId)
values(1,4,'D201',3,5);
 
 insert into Subjects_3(Id,Name)
values(1,'Credit');

insert into Teachers_3( Id,Name,Salary,Surname)
values (1,'Dave McQueen',12000,'Dave McQueen'),
(2,   'Иван',  132,  'Иванов'),
(3,  'Петр', 289 ,'Петров');





select * from Departments_3;

select * from Faculties_3;

select * from Groups_3;

select * from GroupsLectures_3;

 select * from Lectures_3;

 select * from Subjects_3;

select * from Teachers_3;
go

--1)
SELECT count(*) AS "Number of teachers of the department: <Software Development>"
from Departments_3 as d  ,Teachers_3 as t 
where t.Id=d.Name 
and d.Name ='Software Development'

--2)
SELECT count(*) AS "Number  of lectures given by the teacher: <Dave McQueen>"
from Lectures_3 as l ,Teachers_3 as t
where l.Id=t.Name    
and t.Name='Dave McQueen';
--3)
SELECT count(*) AS "Number of classes held in the classroom: <D201>"
from Lectures_3 as l, GroupsLectures_3 as gl 
where l .LectureRoom=gl.LecturesId 
and l.LectureRoom='D201';
--4)
Select  LectureRoom ,LecturesId
from Lectures_3 as l,  GroupsLectures_3 as gl 
where l .LectureRoom=gl.LecturesId 

--5)
SELECT count(*) AS "Number  of students given by the teacher: <Dave McQueen>"
from GroupsLectures_3 as gl ,Teachers_3 as t
where gl.GroupId=t.Name    
and t.Name='Jack Underhill';

--6)
SELECT AVG(Salary) AS [Output the average teacher rate[]
FROM Teachers_3;

--7)
SELECT MAX(Id)  AS [Maximum  number of students]
FROM Groups_3;
SELECT MIn(Id)  AS [Minimum number of students]
FROM Groups_3;

--8)
SELECT AVG(Financing) AS [Average financing ]
FROM Departments_3;

--9)
SELECT t.Name,t.Surname,COUNT(s.Id) 
from Teachers_3 as t,Subjects_3 as s 
where t.Id=s.Id
GROUP BY t.Name,t.Salary;

--10)
select l.DayOfWeek , sum(l.Id)
from Lectures_3 as l
group by l.DayOfWeek;

--11)
select l.LectureRoom, COUNT(d.Id)
from Departments_3 as d, Lectures_3 as l
where d.Id=l.Id
group by l.LectureRoom ;

--12)
select  d.Name, COUNT(s.Id)
from Departments_3 as d, Subjects_3 as s
where d.Name=s.Id
group by d.Name  ;



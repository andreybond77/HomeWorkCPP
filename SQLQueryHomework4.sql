--1
create table Curators(
Id int identity primary key
,Name nvarchar(max) CHECK(Name > '')  NOT NULL
, Surname nvarchar(max) CHECK(Surname > '') NOT NULL
);
--2
create table Departments(
Id int identity primary key
,Financing money CHECK(Financing >0)
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
,FacultyId int not null foreign key (FacultyId) references Departments(Id) 
);
--3
create table Faculties(
Id int identity primary key
,Financing money CHECK(Financing >0)
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);
--4
create table Groups(
Id int identity primary key
, Name nvarchar(10) CHECK(Name > '') UNIQUE NOT NULL
,Year int  CHECK( Year>=1 AND Year<=5)NOT NULL
,DepartmentId int not null foreign key (DepartmentId) references Groups(Id)
);
--5
create table GroupsCurators(
Id int identity primary key
,CuratorId int not null foreign key (CuratorId) references GroupsCurators(Id)
,GroupId int not null foreign key (Groupid) references GroupsCurators(Id)
);

--6
create table GroupsLectures(
Id int identity primary key
,GroupId int not null foreign key (Groupid) references GroupsLectures(Id)
,LecturesId int not null foreign key (LecturesId) references GroupsLectures(Id)
);

--7
create table Lectures(
Id int identity primary key NOT NULL
,LectureRoom nvarchar(max) CHECK(LectureRoom > '') NOT NULL
,SubjectId int NOT NULL foreign key (SubjectId) references Lectures(Id)
,TeachersId int NOT NULL foreign key (TeachersId) references Lectures(Id)
);

--8
create table Subjects (
Id int identity primary key
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);

--9
create table Teachers(
 Id int identity primary key
 , IsProfessor bit NOT NULL DEFAULT 0
 , Name nvarchar(max) CHECK(Name > '') NOT NULL
 ,Salary money CHECK(Salary>0) NOT NULL
 ,Surname nvarchar(max) CHECK(Surname > '')
 );

 insert into Curators (Id,Name,Surname)
values('Ivan','Ivanov');

insert into Departments(Id,Financing,Name,FacultyId)
values(1,1200,'Economics');

insert into Faculties(Name)
values ('Credit');

insert into Groups (Id,Name,Year,DepartmentId)
values('A-27',3,4);

insert into GroupsCurators(Id,CuratorId,GroupId)
values(4,3);

insert into GroupsLectures(Id,GroupId,LecturesId)
values(4,3);

 insert into Lectures(Id,LectureRoom,SubjectId,TeachersId)
values(4,3,5);

 
 insert into Subjects(Id,Name)
values('Credit');


insert into Teachers(Id, Name,Salary,Surname)
values ('Petia',12000,'Victorov');



select * from Curators;

select * from Departments;

select * from Faculties;

select * from Groups;

select * from GroupsCurators;

select * from GroupsLectures;

 select * from Lectures;

 select * from Subjects;

select * from Teachers;
go

--1) Вывестивсе возможныепары строкпреподавателей и групп
SELECT t. Name + ' ' + Surname as TeachersName, g.Name as GroupName
FROM  Teachers as t,Groups as g
WHERE t.Id = g.Id;

--2)Вывести названия факультетов, фонд финансирования
--  кафедр которых превышает фонд финансирования факультета

select f.Name as FacultiesName
From Faculties as f,Departments as d
where f.Financing> d.Financing

--3)Вывести фамилии кураторов групп и названия групп, которые они курируют.
select c.Surname as Surname,g.Name as GroupName
From Curators as c,Groups as g
WHERE c.Id = g.Id;

 --4)Вывести имена ифамилии преподавателей, которые читают
--лекции у группы “P107”.

SELECT t. Name + ' ' + t.Surname as TeachersName, g.Name as GroupName_p107
FROM  Teachers as t,Groups as g
WHERE t.Id = g.Id
and g.Name='P107';

--5)Вывести фамилии преподавателей и названия факультетов
--на которых они читают лекции.
SELECT t. Surname as TeachersName, f.Name as FacultiesName
FROM  Teachers as t,Faculties as f
WHERE t.Id = f.Id

--6)Вывести названия кафедр и названия групп, которые к
--ним относятся.
SELECT  d.Name as DepartmentsMame ,g.Name as GroupName
FROM  Departments as d,Groups as g
WHERE d.Id = g.DepartmentId

--7)Вывести названия дисциплин, которые читает преподаватель “Samantha Adams”
SELECT s. Name as Samantha_Adams
FROM  Subjects as s,Teachers as t
WHERE s.Id = t.Id 
and t.Name='Samantha Adams'

--8)Вывести названия кафедр,на которых читается дисциплина"Database Theory"
SELECT d. Name as DepartmentsMame
FROM  Departments as d,Subjects as s
WHERE s.Id = s.Id 
and s.Name='Database Theory'

 --9)Вывести названия групп, которые относятся к факультету
--“Computer Science”.
select g.Name as GroupName
From Groups as g,Faculties as f
WHERE g.Id = f.Id
and f.Name='Computer Science'

--10)Вывести названия групп 5-го курса,
--а также название факультетов, к которым они относятся.
SELECT  g.Name as GroupName_5th_year
FROM  Groups as g
WHERE g.Year=5;

--11)Вывести полные имена преподавателей и лекции, которые
--они читают (названия дисциплин  игрупп),причем отобрать
--только те лекции, которые читаются в аудитории “B103”.
SELECT t. Name + ' ' + t.Surname as TeachersName, s.Name as SubjectsName
FROM  Teachers as t,Subjects as s,Lectures as l
WHERE t.Id = l.Id 
and s.Id = l.Id
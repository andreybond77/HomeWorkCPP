--1
create table Curators_3(
Id int identity primary key
,Name nvarchar(max) CHECK(Name > '')  NOT NULL
, Surname nvarchar(max) CHECK(Surname > '') NOT NULL
);
--2
create table Departments_3(
Id int identity primary key
,Bulding int  CHECK( Bulding>=1 AND Bulding <=5)NOT NULL
,Financing money CHECK(Financing >0)
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
,FacultyId int not null
,foreign key (FacultyId) references Departments_1(Id) 
);
--3
create table Faculties_3(
Id int identity primary key
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);
--4
create table Groups_3(
Id int identity primary key
, Name nvarchar(10) CHECK(Name > '') UNIQUE NOT NULL
,Year int  CHECK( Year>=1 AND Year<=5)NOT NULL
,DepartmentId int not null foreign key (DepartmentId) references Groups_1(Id)
);
--5
create table GroupsCurators_3(
Id int identity primary key
,CuratorId int not null foreign key (CuratorId) references GroupsCurators(Id)
,GroupId int not null foreign key (Groupid) references GroupsCurators(Id)
);

--6
create table GroupsLectures_3(
Id int identity primary key
,GroupId int not null foreign key (Groupid) references GroupsLectures(Id)
,LecturesId int not null foreign key (LecturesId) references GroupsLectures(Id)
);

--7
create table GroupsStudents_3(
Id int identity primary key
,GroupId int not null foreign key (Groupid) references GroupsStudents_3(Id)
,StudentsId int not null foreign key (StudentsId) references GroupsStudents_3(Id)
);

--8
create table Lectures_3(
Id int identity primary key
,Date date CHECK(Date <= GETDATE())
,GroupId int not null foreign key (Groupid) references GroupsStudents_3(Id)
,SubjectId int not null foreign key (SubjectId) references Lectures(Id)
,TeacherId int not null foreign key (TeacherId) references Lectures(Id)
);

--9
create table Students_3(
Id int identity primary key
, Name nvarchar(max) CHECK(Name > '')  NOT NULL
,Rating int CHECK( Rating >=1 AND Rating <+5) NOT NULL
, Surname nvarchar(max) CHECK(Surname > '') NOT NULL
)

--10
create table Subjects_3 (
Id int identity primary key
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);

--11
create table Teachers_3(
 Id int identity primary key
 , IsProfessor bit NOT NULL DEFAULT 0
 , Name nvarchar(max) CHECK(Name > '') NOT NULL
 ,Salary money CHECK(Salary>0) NOT NULL
 ,Surname nvarchar(max) CHECK(Surname > '')
 );


 insert into Curators_3 (Name,Surname)
values('Ivan','Ivanov');

insert into Departments_3(Bulding,Financing,Name,FacultyId)
values(1,1200,'Economics');

insert into Faculties_3(Name)
values ('Credit');

insert into Groups_3 (Name,Year,DepartmentId)
values('A-27',3,4);

insert into GroupsCurators_3(CuratorId,GroupId)
values(4,3);

insert into GroupsLectures_3(GroupId,LecturesId)
values(4,3);

insert into GroupsStudents_3(GroupId,StudentsId)
values(4,3);
 
 insert into Lectures_3(Date,SubjectId,TeacherId)
values(4,3,5);

insert into Students_3(Name,Rating,Surname)
values('Igor',3,'Cocosov');
 
 insert into Subjects(Name)
values('Credit');


insert into Teachers_3(IsProfessor, Name,Salary,Surname)
values ('Petia',12000,'Victorov');



select * from Curators_3;

select * from Departments_3;

select * from Faculties_3;

select * from Groups_3;

select * from GroupsCurators_3;

select * from GroupsLectures_3;

 select * from GroupsStudents_3;

 select * from Lectures_3;

 select * from Students_3;

 select * from Subjects_3;

select * from Teachers_3;
go

--1)Вывести номера корпусов, если суммарный фонд финансирования расположенных в них кафедр превышает 100000. 

SELECT d.Bulding as NamberBulding
FROM Departments_3 as d
WHERE sum(d.Financing )>1000000;

--2)Вывести названия групп 5-го курса кафедры "Software Development”, которые имеют более 10 пар в первуюнеделю.
SELECT g.Name as GroupName
FROM Groups_3 AS g, Departments AS d,GroupsLectures AS gl, Lectures AS l
WHERE d.Name='Software Development' AND g.DepartmentId=d.ID AND g.year=5 AND gl.GroupId=g.Id 
AND l.id= any (SELECT l.id FROM Lectures AS l WHERE DAY(l.Date)<=7)
GROUP BY g.Name
HAVING COUNT(GL.id)>10

--3)Вывести названия групп, имеющих рейтинг(средний рейтинг всех студентов группы) больше, чем рейтинггруппы
--“D221”.
SELECT g.Name as RatingGroups 
FROM Groups_3 as g ,Students_3 as s
WHERE avg(s.Rating )>  s.Rating and g.Name='D221' 


--4)Вывести фамилии и имена преподавателей, ставка которых
--выше средней ставки профессоров.
select t.Name+''+t.Surname
FROM Teachers_3 as t
WHERE  t.Salary  > avg (t.Salary = any (t.IsProfessor=1))  
GROUP BY t.Name

--5)Вывести названия групп, укоторых больше одного куратора
select g.Name as Groups_name
From GroupsCurators_3 as gc, Groups_3 as g
where  count(gc.CuratorId)>1

--6)Вывести названия групп, имеющих рейтинг(средний рейтинг всех студентов группы) меньше, чем минимальный
--рейтинг групп 5-го курса.
SELECT g.Name as RatingGroups 
FROM Groups_3 as g ,Students_3 as s
WHERE avg(s.Rating )< sum(select min( s.Rating =any(select g.year=5)))

--7)Вывести названия факультетов, суммарный фонд финансирования кафедр которых больше суммарного фонда
--финансирования кафедр факультета “Computer Science”

select d.Name as NameDepartmens
from Departments_3 as d
where sum(d.Financing)>sum(d.Financing = any(select d.Name ='Computer Science'))

--8)Вывести названия дисциплин и полные имена преподавателей, читающих наибольшее количество лекций по ним.
select s.Name as NameSubjects,t.Name+''+t.Surname as NameTeachers
from Subjects_3 as s, Teachers_3 as t
where
--9)Вывести название дисциплины, по которому читается
--меньше всего лекций.
select s.Name as NameSubjects
from Subjects_3 as s,lectures_3 as l
where 

--10)Вывести количество студентов и читаемых дисциплин на кафедре "Software Development” select count (st.Id) as NumberofStudents,count(su.Id) as NumberofSubjects From Students_3 as st,Subjects_3 as su, Departments_3 as dwhere d.Name='Software Development'
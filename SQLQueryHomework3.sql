create table Departments(
Id int identity primary key
,Financing money CHECK(Financing >0)
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);
create table Faculties(
Id int identity primary key
,Dean nvarchar(max) CHECK(Dean > '')NOT NULL
,Name nvarchar(100) CHECK(Name > '') UNIQUE NOT NULL
);
create table Groups(
Id int identity primary key
, Name nvarchar(10) CHECK(Name > '') UNIQUE NOT NULL
,Rating int CHECK( Rating >=1 AND Rating <+5) NOT NULL
,Year int  CHECK( Year>=1 AND Year<=5)NOT NULL
);
create table Teachers(
 Id int identity primary key
 , EmploymentDate date CHECK(EmploymentDate > '01-01-1990')
 , IsAssistant bit NOT NULL DEFAULT 0
 , IsProfessor bit NOT NULL DEFAULT 0
 , Name nvarchar(max) CHECK(Name > '') NOT NULL
 , Position nvarchar(max) CHECK(Position > '') NOT NULL
 ,Premium money CHECK(Premium>0)NOT NULL
 ,Salary money CHECK(Salary>0) NOT NULL
 ,Surname nvarchar(max) CHECK(Surname > '')
 );



insert into Departments(Financing,Name)
values(1200,'Economics');

insert into Faculties(Name,Dean)
values ('Credit','Ivanov');

insert into Groups (Name,Rating,Year)
values('A-27',3,4);

insert into Teachers(EmploymentDate,IsAssistant,IsProfessor, Name,Premium,Salary,Surname)
values ('22-03-2003','Petrov','Sidorov''Victor',1000,23000,'Slavin');





select * from Departments;

select * from Faculties;

 select * from Groups;

select * from Teachers;
go
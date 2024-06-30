

create table Staff(
  Id int identity primary key NOT NULL
, NameStaff nvarchar(100) CHECK(NameStaff > '') UNIQUE NOT NULL
, Post nvarchar(100) CHECK(Post > '')  NOT NULL
, DateAdmission date NOT NULL
, Gender VARCHAR(1) CHECK (gender IN ('F', 'M'))
, Salary money CHECK(Salary >0) not null
);

create table Customers(
Id int identity primary key NOT NULL
, NameCustomers nvarchar(100) CHECK(NameCustomers > '') UNIQUE NOT NULL
, Email nvarchar(100) CHECK(Email > '')  NOT NULL
, ContactPhone  nvarchar(100) CHECK(ContactPhone > '')  NOT NULL
, Gender VARCHAR(1) CHECK (gender IN ('F', 'M'))
, OrderHistory nvarchar(100) CHECK(OrderHistory > '')  NOT NULL
, DiscountPercentage int CHECK( DiscountPercentage < 30 ) not null
, MailingList VARCHAR(1) CHECK (MailingList IN ('Y', 'N'))
);


create table Products(
  Id int identity primary key NOT NULL
, NameProducts nvarchar(100) CHECK(NameProducts > '') UNIQUE NOT NULL
, ViewProducts nvarchar(100) CHECK(ViewProducts > '') UNIQUE NOT NULL
, QuantityProducts int not null
, CostPrice money CHECK(CostPrice >0) not null
, Manufacturer nvarchar(100) CHECK(Manufacturer > '') UNIQUE NOT NULL
, SalePrice money CHECK(SalePrice >0) not null
);


create table Sales(
Id int identity primary key NOT NULL
, NameProducts nvarchar(100) CHECK(NameProducts > '') UNIQUE NOT NULL
, SalePrice money CHECK(SalePrice >0) not null
, QuantityProducts int not null
, DateSale date NOT NULL
, InformationSeller nvarchar(100) CHECK(InformationSeller > '') UNIQUE NOT NULL
, foreign key (InformationSeller) references Staff (NameStaff) 
, InformationBuyer nvarchar(100) CHECK(InformationBuyer > '') UNIQUE NOT NULL
, foreign key (InformationBuyer) references Customers(NameCustomers) 
);

create table History 
(
    Id int identity primary key NOT NULL
 ,   ProductId int NOT NULL
 ,  DateSale date NOT NULL
 ,   Operation nvarchar (200) NOT NULL
 ,  CreateAt datetime NOT NULL default getdate()
);

insert into Staff(NameStaff,Post,DateAdmission,Gender,Salary)
values('Ivanov Ivan','Economist','23,02,2007','M',2500)


insert into Customers(NameCustomers,Email,ContactPhone,Gender,OrderHistory,DiscountPercentage,MailingList)
values('Petrov Petr','petr@mail.ru','89085037759','M','wfwfwfw',15,'Y')
--,     ('Semenov Igor','petr@mail.ru','89085037543','M','wfw3iu3fwfw',15,'N')
--,     ('Petrov Petrf','petr@mai5ul.ru','89085037453','M','wfwf3uiwfw',15,'N')
--,     ('Petrov Petru','petr@maiu5l.ru','89052252523','M','wfwkfwfw',15,'Y');

select * from Staff

select * from Customers
go



 create trigger CustomersUpdate
 on Customers
 for update
 as
 declare @Name varchar(50)
 if (select NameCustomers from Customers)= @Name
 begin
 print 'Such a client already exists'
 end
 go

 create trigger CustomersDelete
 on Customers
 for delete
 as
 begin
 insert into History (ProductId, Operation, DateSale)
 select Id, 'Sold goods' + NameProducts + ' Firm ' + Manufacturer +'Date sale'
 from inserted
 end
 go

 create trigger StaffUpdate
 on Staff 
 for update
 as 
 if (select NameStaff from Staff)=(select NameCustomers from Customers )
 begin
 print 'Adding a new seller is canceled'
 end
 go

 create trigger CustomersUpdate
 on Customers
 for update
 as
 if (select NameCustomers from Customers)= (select NameStaff from Staff)
 begin
 print 'Adding a new customer is canceled'
 end
 go

 create trigger Products
 on Products
 for update
 as 
 if (select NameProducts from Products)='apples' 
  if (select NameProducts from Products)='pears'
   if (select NameProducts from Products)='plums'
    if (select NameProducts from Products)='coriande'
 begin
 print 'It does not allow you to insert information about the sale of such products'
 end
 go
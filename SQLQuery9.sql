

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


create trigger ProductsUpdate
 on Products
 for update
 as
 insert into History (ProductId, Operation, DateSale)
 select Id, 'Sold goods' + NameProducts + ' Firm ' + Manufacturer +'Date sale'+ DateSale
 from inserted
 go

create trigger ProductsNull
 on Products
 for update
 as 
 if (select QuantityProducts from Products)<=0 
 begin
 insert into History (ProductId, Operation, DateSale)
 select Id, 'Sold goods' + NameProducts + ' Firm ' + Manufacturer +'Date sale'+ 'The product is sold'
 from inserted
 end
 go


create trigger CustomersUpdate
on Customers
for update
 as
 declare @Name varchar(50)
 declare @Email nvarchar(100)
 if (select NameCustomers  from Customers ) = @Name and
    (select Email  from Customers ) = @Email
 begin
 print 'The client is already in the database'
 end
 go

 create trigger CustomersDelete
 on Customers
 for delete
 as
 declare @Name varchar(50)
 if (select NameCustomers from Customers)= @Name
 begin
 print 'You cannot delete this client'
 end
 go

 create trigger StaffDelete
 on Staff
 for delete
 as 
 declare @Date date
 if (select DateAdmission from Staff)< @Date
 begin
 print 'Prohibit the removal of employees'
 end
 go

create trigger ProductsSum
 on Products
for update
 as 
 if (select sum(SalePrice) from Products)>=50000 
 begin
 print 'The purchase amount including the discount:'+sum(SalePrice)*0.15
 end
 go

 create trigger ProductsManufacturer
  on Products
for update
 as 
 if (select Manufacturer from Products)= 'Sports, sun and barbell' 
 begin
 print 'Prohibit the addition of this companys product'
 end
 go

 create trigger ProductsQuantity
  on Products
for update
 as 
 if (select QuantityProducts from Products)= 1 
 begin
insert into History (ProductId, Operation, DateSale)
 select Id, 'Sold goods' + NameProducts + ' Firm ' + Manufacturer +'Date sale'+ 'The last unit'
 from inserted
 end
 go


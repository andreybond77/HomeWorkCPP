
using SimpleProject;
using System;
using System.Dynamic;
using System.Reflection;
using static System.Console;
namespace SimpleProject
{


    
    public abstract class Storage
    {
     
        string _nameofthemedia;
        string _model;
        

        public Storage(string nameofthemedia,
            string model, int fullmemory
             )
        {
            _nameofthemedia=nameofthemedia;
            _model=model;
            


        }
        public virtual void Print()
        {
            WriteLine($"\nMedia Name: {_nameofthemedia} \nModel: {_model}");
        }
        public abstract int Speed();
        public abstract int Memory();
        public abstract int Copying();
        public abstract int ReceivingMemory();
        public abstract void GettingInformation();
       
    }
    
}
    class Flash : Storage
{
        
        int _fullmemory;
        int _memory;
    int _speed;
    public Flash (string nameofthemedia, string model,

         int fullmemory, int memory, int speed) :
        base( nameofthemedia, model,fullmemory)
    {
        _fullmemory=fullmemory;
        _memory = memory;
        _speed=speed;
       
    }
        public override int Memory()
        {
        WriteLine("The amount of memory: "+_fullmemory + " Gb");
        return _fullmemory;
    }
    public override int Speed()
    {
        return _speed;
    }
    public override int Copying()

    {

        WriteLine("Copied: "+_memory + " Gb");
        return _memory;
    }
    public override int ReceivingMemory()
    {
        WriteLine("Freely: " +(_fullmemory-_memory) + " Gb");
        return _fullmemory;
    }
   

    public override void GettingInformation()
        {
        WriteLine();
        WriteLine("-----------------------------------------------------");
        WriteLine("    Information about the device. ");
        WriteLine("The amount of memory: "+_fullmemory + " Gb");
        WriteLine("Speed: "+_speed + " Gb/s");
        WriteLine("Copied: "+_memory + " Gb");
        WriteLine("Freely: " +(_fullmemory-_memory) + " Gb");
        WriteLine("------------------------------------------------------");
    }
    }


class DVD : Storage
{
   
    int _fullmemory;
    int _memory;
    int _speed;
    public DVD(string nameofthemedia, string model,

          int fullmemory, int memory, int speed) :
        base(nameofthemedia, model, fullmemory)
    {
        _fullmemory=fullmemory;
        _memory = memory;
        _speed=speed;

    }
    public override int Speed()
    {
        return _speed;
    }
    public override int Memory()
    {
        WriteLine("The amount of memory: "+_fullmemory + " Gb");
        return _fullmemory;
    }

    public override int Copying()

    {

        WriteLine("Copied: "+_memory + " Gb");
        return _memory;
    }
    public override int ReceivingMemory()
    {
        WriteLine("Freely: " +(_fullmemory-_memory) + " Gb");
        return _fullmemory;
    }

    public override void GettingInformation()
    {

        WriteLine();
        WriteLine("-----------------------------------------------------");
        WriteLine("    Information about the device. ");
        WriteLine("The amount of memory: "+_fullmemory + " Gb");
        WriteLine("Speed: "+_speed + " Gb/s");
        WriteLine("Copied: "+_memory + " Gb");
        WriteLine("Freely: " +(_fullmemory-_memory) + " Gb");
        WriteLine("------------------------------------------------------");
    }
}   
    class HDD : Storage
    {
    
    int _fullmemory;
    int _memory;
    int _speed;
   
    public HDD(string nameofthemedia, string model,

        int fullmemory, int memory, int speed) :
        base(nameofthemedia, model, fullmemory)
    {
        _fullmemory=fullmemory;
        _memory = memory;
        _speed=speed;
    }
    public override int Speed()
    {
        return _speed;
    }
    public override int Memory()
    {
        WriteLine("The amount of memory: "+_fullmemory + " Gb");
        return _fullmemory;
    }

    public override int Copying()

    {

        WriteLine("Copied: "+_memory + " Gb");
        return _memory;
    }
    public override int ReceivingMemory()
    {
        WriteLine("Freely: " +(_fullmemory-_memory) + " Gb");
        return _fullmemory;
    }


    public override void GettingInformation()
    {
        WriteLine();
        WriteLine("-----------------------------------------------------");
        WriteLine("    Information about the device. ");
        WriteLine("The amount of memory: "+_fullmemory + " Gb");
        WriteLine("Speed: "+_speed + " Gb/s");
        WriteLine("Copied: "+_memory + " Gb");
        WriteLine("Freely: " +(_fullmemory-_memory) + " Gb");
        WriteLine("------------------------------------------------------");
    }
    
}

    class Program
    {
        static void Main(string[] args)
        {
        Storage[] learners =
        {
 new Flash("John", "Doe", 6, 2,2),

 new DVD("Jack", "Smith", 4, 1, 2),

 new HDD("Bill", "Maks", 9, 3,3)

 };
        Console.WriteLine("\r\nThe application should provide the following features:" +
            "\r\n1- calculation of the total amount of memory of all devices;" +
            "\r\n2- copying information to devices;" +
            "\r\n3- calculation of the time required for copying;" +
            "\r\n4- calculation of the required number of media of the presented types for information transfer");
        Console.WriteLine("---------------------------------------------------------");
        Console.WriteLine("Enter task number:");
        int taskNumber = int.Parse(Console.ReadLine());
        switch (taskNumber)
        {
            case 1: SolveTask1(); break;
            case 2: SolveTask2(); break;
            case 3: SolveTask3(); break;
            case 4: SolveTask4(); break;
            default: Console.WriteLine("Unknown task"); break;
        }
        Console.ReadKey();
          void SolveTask1()
            
        {
            Console.WriteLine("calculation of the total amount of memory of all devices:");
            int x = 0;
            foreach (Storage item in learners)
            {

                x+=item.Memory();

            }
            WriteLine("Total amount of memory: "+ x + " Gb");
        }

        WriteLine();
        void SolveTask2()

        {
            Console.WriteLine("copying information to devices:");
            int x = 0;
            foreach (Storage item in learners)
            {

                x+=item.Copying();

            }
            WriteLine("The total amount of information copied: "+ x + " Gb");
        }
        WriteLine();
        void SolveTask3()

        {
            Console.WriteLine("Сalculation of the time required for copying:");
            int x = 0;
       
            foreach (Storage item in learners)
            {

                x+=(item.Copying()/item.Speed());
               
            }
            WriteLine("time for a full copy: "+ x + " Gb");
        }
        WriteLine();
        void SolveTask4()

        {
            WriteLine();
            foreach (Storage item in learners)
            {
                item.Print();
                item.Memory();
                item.Copying();
                item.ReceivingMemory();
                item.GettingInformation();

            }

        }

    }
    
    }





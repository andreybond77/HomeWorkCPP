using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.ComponentModel.Design;
using System.Globalization;
using System.Linq;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using static System.Formats.Asn1.AsnWriter;

namespace LessonTasks
{
    
    internal static class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter task number:");
            int taskNumber = int.Parse(Console.ReadLine());
            switch (taskNumber)
            {
                case 1: SolveTask1(); break;
                case 2: SolveTask2(); break;
                case 3: SolveTask3(); break;
                case 4: SolveTask4(); break;
                case 5: SolveTask5(); break;
                case 6: SolveTask6(); break;
                default: Console.WriteLine("Unknown task"); break;
            }
            

        }

        private static void SolveTask1()

        {



            Console.WriteLine("Введите длинну стороны квадрата:");
            int numberRow = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите символ:");
            //char s = char.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            string[,] nums = new string[numberRow, numberRow];


            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberRow; j++)
                {
                    nums[i, j] = s;
                }
            }

            // Вывод исходного массива на экран
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberRow; j++)
                {
                    Console.Write("{0,4}", nums[i, j]);
                }
                Console.WriteLine();
            }





        }

        private static void SolveTask2()
        {

            int num, rem, sum = 0, temp;

            Console.WriteLine("\n >>>> To Find a Number is Palindrome or not <<<< ");
            Console.Write("\n Enter a number: ");
            num = Convert.ToInt32(Console.ReadLine());
            temp = num;
            while (Convert.ToBoolean(num))
            {
                rem = num % 10;
                num = num / 10;
                sum = sum * 10 + rem;

            }
            Console.WriteLine("\n The Reversed Number is: {0} \n", sum);
            if (temp == sum)
            {
                Console.WriteLine("\n Number is Palindrome \n\n");
            }
            else
            {
                Console.WriteLine("\n Number is not a palindrome \n\n");
            }
            Console.ReadLine();

        }

        private static void SolveTask3()
        {
            int[] Array1 = new int[] { 1, 2, 6, -1, 88, 7, 6 };
            Console.WriteLine("Оригинальный массив");
            for (int i = 0; i<Array1.Length; i++)
            {
                Console.Write(Array1[i]);
            }

            int[] Array2 = new int[] { 6, 88, 7 };
            Console.WriteLine("\nМассив для фильтрации");
            for (int i = 0; i < Array2.Length; i++)
            {
                Console.Write(Array2[i] + " ");
            }

            Console.WriteLine("\nМассив после фильтрации");

            var Array3 = new ArrayList();

            for (int i = 0; i < Array1.Length; i++)
            {

                if (Array2.Contains(Array1[i]) == false)
                {
                    Array3.Add(Array1);
                   
                }
                
            }
            var ArrayRes = Array3.ToArray();
            for (int i = 0; i < ArrayRes.Length; i++)
            {
                Console.WriteLine(ArrayRes[i]+"");
            }






        }







        private static void SolveTask4()
        {
            Website rab = new Website();
            rab.GetInfo();
            rab.Setifo();
            Console.ReadKey();


        }

        private static void SolveTask5()
        {
            Journal rab = new Journal();
            rab.GetInfo();
            rab.Setifo();
            Console.ReadKey();

        }
        static void SolveTask6()
        {
            Store rab = new Store();
            rab.GetInfo();
            rab.Setifo();
            Console.ReadKey();


        }

       

        class Website
        {
            private string name_site;
            private string path_site;
            private string description_site;
            private int ip_address_site;

            public void GetInfo()
            {
                Console.WriteLine("Enter the site name");
                name_site = Console.ReadLine();
                Console.WriteLine("Enter the path to the site");
                path_site = Console.ReadLine();
                Console.WriteLine("Enter a description of the site");
                description_site = Console.ReadLine();
                Console.WriteLine("Enter the IP address of the site");
                ip_address_site =Convert.ToInt32(Console.ReadLine());
                Console.WriteLine();
            }

            public void Setifo()
            {
                Console.WriteLine("Site name: {0} " +
                    "\t\nPath to the site: {1}"+
                    "\t\nDescription of the site: {2}"+
                    "\t\nIP address of the site: {3}",
                    name_site,
                    path_site,
                    description_site,
                    ip_address_site);
            }
        }

        class Journal
        {
            private string name_journal;
            private int year_of_foundation;
            private string description_journal;
            private int contact_phone_number;
            private string contact_e_mail;

            public void GetInfo()
            {
                Console.WriteLine("Enter the journal name");
                name_journal = Console.ReadLine();
                Console.WriteLine("Enter the year the journal was founded");
                year_of_foundation = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter a description of the journal");
                description_journal = Console.ReadLine();
                Console.WriteLine("Enter the contact phone number");
                contact_phone_number =Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the contact e-mail");
                contact_e_mail =Console.ReadLine();
                Console.WriteLine();
            }

            public void Setifo()
            {
                Console.WriteLine("Journal name: {0} " +
                    "\t\nYear the journal was founded: {1}"+
                    "\t\nDescription of the journal: {2}"+
                    "\t\nContact phone number: {3}"+
                    "\t\nContact e-mail: {4}",
                    name_journal,
                    year_of_foundation,
                    description_journal,
                    contact_phone_number,
                    contact_e_mail);
            }
        }
        class Store
        {
            private string name_store;
            private string address;
            private string description_store;
            private int contact_phone_number;
            private string contact_e_mail;

            public void GetInfo()
            {
                Console.WriteLine("Enter the store name");
                name_store = Console.ReadLine();
                Console.WriteLine("Enter the store's address");
                address = Console.ReadLine();
                Console.WriteLine("Enter a description of the store's profile");
                description_store = Console.ReadLine();
                Console.WriteLine("Enter the contact phone number");
                contact_phone_number =Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the contact e-mail");
                contact_e_mail =Console.ReadLine();
                Console.WriteLine();
            }

            public void Setifo()
            {
                Console.WriteLine("Store name: {0} " +
                    "\t\nStore address: {1}"+
                    "\t\nDescription of the store's profile: {2}"+
                    "\t\nContact phone number: {3}"+
                    "\t\nContact e-mail: {4}",
                    name_store,
                    address,
                    description_store,
                    contact_phone_number,
                    contact_e_mail);
            }
        }


        private static int ParseSingleNumberArgument(string[] args)
        {
            if (args.Length != 1)
                throw new ApplicationException("args.Length != 1");

            return int.Parse(args[0]);
        }
    }
}

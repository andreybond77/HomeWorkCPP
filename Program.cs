using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

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
                case 7: SolveTask7(); break;
                default: Console.WriteLine("Unknown task"); break;
            }
        }

        private static void SolveTask1()

        {

            int numberRow_1 = 5; // Количество строк
            Console.WriteLine("Одномерный массив:");
            int[] nums_1 = new int[numberRow_1];


            // Заполнение массива числами с консоли

            for (int i = 0; i < numberRow_1; i++)
            {


                nums_1[i] = Convert.ToInt32(Console.ReadLine()); ;

            }

            // Вывод исходного массива на экран
            for (int i = 0; i < numberRow_1; i++)
            {


                Console.Write("{0} ", nums_1[i]);

            }
            Console.WriteLine();

            //  Поиск максимального и минимального элементов
            int sum_1 = 0;
            int sum_12 = 0;
            int comp_1 = 1;
            int max_1 = nums_1[0], min_1 = max_1;
            for (int i = 0; i < numberRow_1; i++)
            {
                sum_1+=nums_1[i];
                comp_1*=nums_1[i];

                if (nums_1[i] > max_1)
                {
                    max_1 = nums_1[i];


                }
                if (nums_1[i] < min_1)
                {
                    min_1 = nums_1[i];

                }
                if (nums_1[i]%2==0)
                {
                    sum_12+=nums_1[i];
                }

            }


            Console.WriteLine();
            Console.WriteLine("Максимальный элемент: {0} ", max_1);
            Console.WriteLine("Минимальный элемент: {0} ", min_1);
            Console.WriteLine("Сумма элементов матрицы : {0} ", sum_1);
            Console.WriteLine("Сумма четных элементов матрицы : {0} ", sum_12);
            Console.WriteLine("Произведение элементов матрицы : {0} ", comp_1);
            //-------------------------------------------------------

            int numberRow = 3; // Количество строк
            int numberCol = 4; // Количество столбцов
            int minRand = 1; // Минимальное значение
            int maxRand = 10; // Максимальное значение



            Console.WriteLine("Двумерный массив:");
            Random rnd = new();
            int[,] nums = new int[numberRow, numberCol];

            // Заполнение массива случайными числами
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberCol; j++)
                {
                    nums[i, j] = rnd.Next(minRand, maxRand);
                }
            }

            // Вывод исходного массива на экран
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberCol; j++)
                {
                    Console.Write("{0,4}", nums[i, j]);
                }
                Console.WriteLine();
            }

            //  Поиск максимального и минимального элементов
            int sum = 0;
            int sum_2 = 0;
            int comp = 1;
            int max = nums[0, 0], min = max;
            int max_common = 0;
            int min_common = 0;
            int sum_odd = 0;
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberCol; j++)
                {
                    if ((j+1)%2!=0)
                    {
                        sum_odd+=nums[i, j];
                    }
                    sum+=nums[i, j];
                    comp*=nums[i, j];
                    if (nums[i, j]%2==0)
                    {
                        sum_2+=nums[i, j];
                    }
                    if (nums[i, j] > max)
                    {
                        max = nums[i, j];
                        if (max<max_1)
                        {
                            max_common=max;
                        }
                        else
                        {
                            max_common=0;
                        }

                    }
                    if (nums[i, j] < min)
                    {
                        min = nums[i, j];
                        if (min>min_1)
                        {
                            min_common=min;
                        }
                        else
                        {
                            min_common=0;
                        }
                    }
                }
            }

            Console.WriteLine();
            Console.WriteLine("Максимальный элемент: {0}", max);
            Console.WriteLine("Минимальный элемент: {0} ", min);
            Console.WriteLine("Сумма элементов матрицы : {0} ", sum);
            Console.WriteLine("Сумма четных элементов матрицы : {0} ", sum_2);
            Console.WriteLine("Сумму нечетных столбцов массива  : {0} ", sum_odd);
            Console.WriteLine("Произведение элементов матрицы : {0} ", comp);
            Console.WriteLine();
            Console.WriteLine("Общий максимальный элемент: {0}", max_common);
            Console.WriteLine("Общий минимальный элемент: {0} ", min_common);
            Console.WriteLine("Общая сумма элементов: {0} ", sum+sum_1);
            Console.WriteLine("Общее произведение элементов: {0} ", comp+comp_1);





        }

        private static void SolveTask2()
        {
            int numberRow = 5; // Количество строк
            int numberCol = 5; // Количество столбцов
            int minRand = -100; // Минимальное значение
            int maxRand = 100; // Максимальное значение
            Console.WriteLine("Исходный массив:");
            Random rnd = new();
            int[,] nums = new int[numberRow, numberCol];

            // Заполнение массива случайными числами
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberCol; j++)
                {
                    nums[i, j] = rnd.Next(minRand, maxRand);
                }
            }

            // Вывод исходного массива на экран
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberCol; j++)
                {
                    Console.Write("{0,4}", nums[i, j]);
                }
                Console.WriteLine();
            }
            //  Поиск максимального и минимального элементов
            int max = nums[0, 0], min = max;
            int sum_max = 0;
            int sum_min = 0;
            int sum = 0;
            int sum_max_1 = 0;
            int sum_min_1 = 0;

            int max_i = 0, max_j = 0, min_i = 0, min_j = 0;
            for (int i = 0; i < numberRow; i++)
            {
                for (int j = 0; j < numberCol; j++)
                {
                    sum_max=sum_max+nums[i, j];
                    if (nums[i, j] > max)
                    {
                        sum_max_1=0;
                        sum_max_1=sum_max;


                        max = nums[i, j];

                        max_i = i;
                        max_j = j;

                    }
                    sum_min=sum_min+nums[i, j];
                    if (nums[i, j] < min)
                    {
                        sum_min_1=0;
                        sum_min_1=sum_min;
                        min = nums[i, j];

                        min_i = i;
                        min_j = j;
                    }

                    if (max_i>min_i)
                    {
                        sum=sum_max_1-sum_min_1;
                    }
                    else
                    {
                        sum=sum_min_1-sum_max_1;
                    }
                }


            }


            Console.WriteLine();
            Console.WriteLine("Максимальный элемент: {0} на позиции [{1},{2}] ", max, max_i+1, max_j+1);
            Console.WriteLine("Минимальный элемент: {0} на позиции [{1},{2}]  ", min, min_i+1, min_j+1);

            Console.WriteLine("Сумма элементов массива, расположенных между минимальным и максимальным элементами: {0} ", sum);
            Console.WriteLine();


        }

        private static void SolveTask3()
        {
            Console.WriteLine("Задание 3");
            Console.WriteLine("Enter the text.");
            Console.WriteLine("Encrypt the text, press e.");
            Console.WriteLine("Decrypt the text d.");




            char Encrypt = char.Parse(Console.ReadLine());
            switch (Encrypt)
            {
                case 'e': Encrypt_E(); break;
                case 'd': Encrypt_D(); break;

                default: Console.WriteLine("Unknown task"); break;
            }





            static void Encrypt_E()
            {



                Console.WriteLine("Введите слово,которое нужно зашифровать:");
                string s = Console.ReadLine();

                Console.WriteLine("Введите ключ:");
                int key = Convert.ToInt32(Console.ReadLine());

                string s1 = "";
                string alfphabet = "АБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЬЪЭЮЯ";
                int m = alfphabet.Length;

                for (int i = 0; i < s.Length; i++)
                {
                    for (int j = 0; j < alfphabet.Length; j++)
                    {
                        if (s[i] == alfphabet[j])
                        {
                            int temp = j + key;

                            while (temp >= m)
                                temp -= m;

                            s1 = s1 + alfphabet[temp];
                        }
                    }

                }
                Console.WriteLine("Зашифрованное слово:" + s1);
                Console.ReadLine();

            }

            static void Encrypt_D()
            {
                Console.WriteLine("Введите слово,которое нужно расшифровать:");
                string s = Console.ReadLine();

                Console.WriteLine("Введите ключ:");
                int key = Convert.ToInt32(Console.ReadLine());

                string s1 = "";
                string alfphabet = "АБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЬЪЭЮЯ";
                int m = alfphabet.Length;

                for (int i = 0; i < s.Length; i++)
                {
                    for (int j = 0; j < alfphabet.Length; j++)
                    {
                        if (s[i] == alfphabet[j])
                        {
                            int temp = j - key;

                            while (temp >= m)
                                temp -= m;

                            s1 = s1 + alfphabet[temp];
                        }
                    }

                }
                Console.WriteLine("Расшифрованное слово:" + s1);
                Console.ReadLine();

            }
        }






        private static void SolveTask4()
        {
            Console.WriteLine("Задание 4");
            Console.WriteLine("Enter the text.");
            Console.WriteLine("Multiplying a matrix by a number, press m.");
            Console.WriteLine("Matrix addition;, press a.");
            Console.WriteLine("The product of matrices., press p.");





            char Matrix = char.Parse(Console.ReadLine());
            switch (Matrix)
            {
                case 'm': Matrix_M(); break;
                case 'a': Matrix_A(); break;
                case 'p': Matrix_P(); break;

                default: Console.WriteLine("Unknown task"); break;
            }
            static void Matrix_M()
            {
                int numberRow = 3; // Количество строк
                int numberCol = 4; // Количество столбцов
                int minRand = 1; // Минимальное значение
                int maxRand = 10; // Максимальное значение



                Console.WriteLine("Двумерный массив:");
                Random rnd = new();
                int[,] nums = new int[numberRow, numberCol];


                // Заполнение массива случайными числами
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        nums[i, j] = rnd.Next(minRand, maxRand);
                    }
                }

                // Вывод исходного массива на экран
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine("Введите множитель:");
                int key = Convert.ToInt32(Console.ReadLine());
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums[i, j]*key);
                    }
                    Console.WriteLine();
                }
            }
            static void Matrix_A()
            {
                int numberRow = 3; // Количество строк
                int numberCol = 4; // Количество столбцов
                int minRand = 1; // Минимальное значение
                int maxRand = 10; // Максимальное значение


                Console.WriteLine();

                Console.WriteLine("Двумерный массив_1:");
                Random rnd = new();
                int[,] nums = new int[numberRow, numberCol];


                // Заполнение массива случайными числами
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        nums[i, j] = rnd.Next(minRand, maxRand);
                    }
                }

                // Вывод исходного массива на экран
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();

                Console.WriteLine("Двумерный массив_2:");
                // Random rnd_2 = new();
                int[,] nums_2 = new int[numberRow, numberCol];


                // Заполнение массива случайными числами
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        nums_2[i, j] = rnd.Next(minRand, maxRand);
                    }
                }

                // Вывод исходного массива на экран
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums_2[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();

                Console.WriteLine("Проссумированные массивы:");
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums_2[i, j]+nums[i, j]);
                    }
                    Console.WriteLine();
                }
            }


            static void Matrix_P()
            {
                int numberRow = 3; // Количество строк
                int numberCol = 4; // Количество столбцов
                int minRand = 1; // Минимальное значение
                int maxRand = 10; // Максимальное значение


                Console.WriteLine();

                Console.WriteLine("Двумерный массив_1:");
                Random rnd = new();
                int[,] nums = new int[numberRow, numberCol];


                // Заполнение массива случайными числами
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        nums[i, j] = rnd.Next(minRand, maxRand);
                    }
                }

                // Вывод исходного массива на экран
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();

                Console.WriteLine("Двумерный массив_2:");
                // Random rnd_2 = new();
                int[,] nums_2 = new int[numberRow, numberCol];


                // Заполнение массива случайными числами
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        nums_2[i, j] = rnd.Next(minRand, maxRand);
                    }
                }

                // Вывод исходного массива на экран
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums_2[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();

                Console.WriteLine("Произведения массивов:");
                for (int i = 0; i < numberRow; i++)
                {
                    for (int j = 0; j < numberCol; j++)
                    {
                        Console.Write("{0,4}", nums_2[i, j]*nums[i, j]);
                    }
                    Console.WriteLine();
                }
            }

        }

        private static void SolveTask5()
        {
            int count = 0;

            Console.WriteLine("Insert your Calculation");
            string calculation = Console.ReadLine();
            string[] splitnumbers = calculation.Split(new Char[] { '+', '-', '*', '/' });
            string[] splitsigns = calculation.Split(new Char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });
            foreach (string s in splitnumbers)
            {
                count++;
                if (s.Trim() != "")
                    Console.WriteLine(s);
                Console.WriteLine(splitsigns[count]);

                Console.WriteLine("For exit press Enter");
                Console.Read();
            }

        }
        private static void SolveTask6()
        {
            Console.WriteLine("\n\tПриложение должно изменять регистр первой буквы\r\n" +
                "каждого предложения на букву в верхнем регистре..");
            Console.WriteLine("\n\tВведите текст");
            string sb = (Console.ReadLine());
            Console.WriteLine();
            sb=sb.ToUpper();
            Console.WriteLine(sb);
        }
        
        private static void SolveTask7()
        {
            int x = 0;
            Console.WriteLine("\n\tПриложение, проверяющее текст на недопустимые слова.");
            Console.WriteLine("\n\tВведите текст");
            StringBuilder sb = new StringBuilder(Console.ReadLine());          
            Console.WriteLine("\n\tВведите недопустимое слово");
            string str = Console.ReadLine();
            Console.WriteLine(sb.Replace(str, "***"));
            

        }
        private static int ParseSingleNumberArgument(string[] args)
        {
            if (args.Length != 1)
                throw new ApplicationException("args.Length != 1");

            return int.Parse(args[0]);
        }
    }
}

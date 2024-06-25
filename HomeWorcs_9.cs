using System;

namespace ConsoleApplication1
{
    
    delegate int LengthLogin(string s);
    delegate bool BoolPassword(string s1, string s2);

    class Program
    {
        private static void SetLogin()
        {
            Console.Write("Введите логин: ");
            string login = Console.ReadLine();

           
            LengthLogin lengthLoginDelegate = s => s.Length;

            int lengthLogin = lengthLoginDelegate(login);
            if (lengthLogin > 4)
            {
                Console.WriteLine("Слишком длинное имя\n");

                
                SetLogin();
            }
        }

        static void Main()
        {
            SetLogin();

            Console.Write("Введите пароль: ");
            string password1 = Console.ReadLine();
            Console.Write("Повторите пароль: ");
            string password2 = Console.ReadLine();

            
            BoolPassword bp = (s1, s2) => s1 == s2;

            if (bp(password1, password2))
                Console.WriteLine("Регистрация удалась!");
            else
                Console.WriteLine("Регистрация провалилась. Пароли не совпадают");

            Console.ReadLine();
        }
    }
}

using System;
using System.Threading;
using System.Threading.Tasks;
using System.Net.Http;

namespace batbongbo
{
    class Program
    {
        static void DoSomeThing(int seconds,string mgs,ConsoleColor color)
        {
          
 
             lock(Console.Out)
            {
                Console.ForegroundColor = color;
                Console.WriteLine($"{mgs,10}.....Start");
                Console.ResetColor();
            }    
            for (int i = 1; i <= seconds; i++)
            {
                lock(Console.Out)
                {
                    Console.ForegroundColor = color;
                    Console.WriteLine($"{mgs,10} {i,2}");
                    Console.ResetColor();
                }    
         
                Thread.Sleep(1000);
            }

           lock(Console.Out)
            {
                Console.ForegroundColor = color;
                Console.WriteLine($"{mgs,10}.....end");
                Console.ResetColor();
            }    
        } 

        static async Task Task2()
        {
            Task t2 = new Task(
              () => {
                  DoSomeThing(10, "T 2", ConsoleColor.Red);
              });
            t2.Start();
            await t2;
            Console.WriteLine("T2 da hoan thanh");
         }
        static async Task Task3()
        {
            Task t3 = new Task(

                (object ob) =>
                {
                    String tentacvu = (String)ob;
                    DoSomeThing(4, tentacvu, ConsoleColor.White);
                }, "T3");
            t3.Start();
            await t3;
            Console.WriteLine("Task 3 hoàn thành");
        }
        static async Task<String> Task4()
        {
            Task<String> t4 = new Task<String>(() =>
            {
                DoSomeThing(10, "T4", ConsoleColor.Yellow);
                return "Return form T4";
            }
          );
            t4.Start();
          var kp=  await t4;
            Console.WriteLine("T4 hoan thanh");
            return t4.Result;
        }
        static async Task<String> Task5()
        {
            Task<String> t5 = new Task<String>(
                (object ob) =>
                {

                    string t = (String)ob;
                    DoSomeThing(4, t, ConsoleColor.Yellow);
                    return "Return form T5";
                }, "T5");

            t5.Start();
            String kp = await t5;
            return kp;
        }
        static async Task<String> Getclint(String url)
        {
            HttpClient httpClinet = new HttpClient();
            Console.WriteLine("BAT DAU TAI");
            HttpResponseMessage kq = await httpClinet.GetAsync(url);
            Console.WriteLine("BAT DAU Doc noi dung");
            string contten=await kq.Content.ReadAsStringAsync();
            Console.WriteLine("Hoan Thanh");
            return contten;

        }
        static async Task Main(string[] args)
        {
            //   Task<String> t4 = Task4();
            // Task<String> t5 = Task5();
            var task = Getclint("https://www.facebook.com/thaithanh.luan.50");

            DoSomeThing(6, "T 1", ConsoleColor.Blue);
            var content = await task;
            Console.WriteLine(content);
           // var kp4 =await t4;
           // var kp5 = await t5;
          //  Console.WriteLine(kp4);
          //  Console.WriteLine(kp5);
            Console.WriteLine("Press any key");
            Console.ReadKey();
        }
    }
}

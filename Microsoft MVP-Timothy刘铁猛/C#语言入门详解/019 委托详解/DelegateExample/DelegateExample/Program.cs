internal class Program
{
    private static void Main(string[] args)
    {
        Calculator calculator = new Calculator();
        Console.WriteLine("直接调用");
        calculator.Report();
        Console.WriteLine("间接调用");
        Action action = new Action(calculator.Report);
        action.Invoke();      // C# 官方版本的调用委托格式
        action();            // C/C++ 函数指针的调用委托方式


        Func<int,int,int> func1 = new Func<int, int, int>(calculator.Add);
        Func<int, int,int> func2 = new Func<int, int, int>(calculator.Sub);

        int x = 100;
        int y = 200;
        int z = 0;

        z = func1.Invoke(x, y);
        Console.WriteLine(z);

        z = func2.Invoke(x, y);
        Console.WriteLine(z);
    }
}

class Calculator
{
    public void Report() { Console.WriteLine("I Have 3 Methods"); }

    public int Add(int a, int b) { return a + b; }

    public int Sub(int a, int b) { return a - b; }
}


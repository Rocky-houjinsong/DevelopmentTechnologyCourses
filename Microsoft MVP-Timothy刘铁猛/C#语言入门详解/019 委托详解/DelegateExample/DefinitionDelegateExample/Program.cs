using System.Transactions;



public delegate double Calc(double x,double y);
class Calculator
{
    public double Add(double x, double y) { return x + y; }
    public double Sub(double x, double y) { return x - y; }
    public double Mul(double x, double y) { return x * y; }
    public double Div(double x, double y) { return x / y; }

}
internal class Program
{
    private static void Main(string[] args)
    {
        Console.WriteLine("自定义委托");
        Calculator calculator = new Calculator();
        Calc calc1 = new Calc(calculator.Add);
        Calc calc2 = new Calc(calculator.Sub);
        Calc calc3 = new Calc(calculator.Mul);
        Calc calc4 = new Calc(calculator.Div);


        double a = 100;
        double b = 200;
        double c = 0;

        c = calc1.Invoke(a, b);
        Console.WriteLine(c);
        c = calc2.Invoke(a, b);
        Console.WriteLine(c);
        c = calc3.Invoke(a, b);
        Console.WriteLine(c);
        c = calc4.Invoke(a, b);
        Console.WriteLine(c);

        // 函数指针的调用方式 
        c = calc1(a, b);
        Console.WriteLine(c);
        c = calc2(a, b);
        Console.WriteLine(c);
        c = calc3(a, b);
        Console.WriteLine(c);
        c = calc4(a, b);
        Console.WriteLine(c);
    }
}


namespace Esercizio2;
using Esercizio1;
using Microsoft.VisualStudio.TestPlatform.ObjectModel;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() {
        _ = Array.Empty<int>().MyTake(123);
        _ = new [] { "ciao" }.MyTake(-1);
        _ = new List<double> { 3.14, 1.23 }.MyTake(10000);
    }

    [Fact]
    public void Test1()
    {
        var source = new int[]{1,2,3,4};
        var result = source.MyTake(-1);
        Assert.Equal(new[]{1,2,3,4}, result);
    }

    [Fact]
    public void Test2()
    {
        var source = Array.Empty<int>();
        var result = source.MyTake(-1);
        Assert.Empty(result);
    }

    [Fact]
    public void Test3()
    {
        var source = new int[]{1,2,3,4};
        var result = source.MyTake(0);
        Assert.Empty(result);
    }

    [Fact]
    public void Test4()
    {
        var source = new List<string>{"aa","bb","cc","dd","ee"};
        var result = source.MyTake(3);
        Assert.Equal(new[]{"aa","bb","cc"}, result);
    }

    [Fact]
    public void Test5()
    {
        var source = new double[]{6.7,4.20};
        var result = source.MyTake(3);
        Assert.Equal(new[]{6.7,4.20}, result);
    }

    [Fact]
    public void Test6()
    {
        var source = new int[]{1,2,3,4};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.MyTake(-2));
    }
}

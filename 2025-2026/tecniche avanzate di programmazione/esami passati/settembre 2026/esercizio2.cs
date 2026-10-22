namespace Esercizio2;

using System.Runtime.CompilerServices;
using Esercizio1;
using Microsoft.VisualStudio.TestPlatform.ObjectModel;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() {
        IEnumerable<int> x = Array.Empty<int>().TakeAccepted(_ => true, 2);
        _ = new List<string> { "a", "b" }.TakeAccepted(s => s.Length == 1, 1);
        _ = new double[] { 3.14, 2.71 }.TakeAccepted(d => d > 0, 0);
    }

    [Fact]
    public void Test1()
    {
        var source = new int[]{1,2,3,4,5};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.TakeAccepted(d => d > 0, -1));
    }

    [Fact]
    public void Test2()
    {
        var source = Array.Empty<int>();
        var result = source.TakeAccepted(d => d/1 == d, 3);
        Assert.Empty(result);
    }

    [Fact]
    public void Test3()
    {
        var source = new int[]{1,2,3,4,5,6};
        var result = source.TakeAccepted(x => x % 2 == 0, 2);
        Assert.Equal([2,4], result);
    }

    [Fact]
    public void Test4()
    {
        var source = new List<string>{"","qui","quo","qua","nonna papera"};
        var result = source.TakeAccepted(x => x.StartsWith("q"), 10);
        Assert.Equal(["qui","quo","qua"], result);
    }

    [Fact]
    public void Test5()
    {
        var source = new int[]{1,3,5,7};
        var result = source.TakeAccepted(x => x % 2 == 0, 3);
        Assert.Empty(result);
    }

    [Fact]
    public void Test6()
    {
        var source = new int[]{10,20,30,40};
        var result = source.TakeAccepted(x => x/1 == x, 0);
        Assert.Empty(result);
    }

}

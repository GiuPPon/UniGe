namespace Esercizio2;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() {
        IEnumerable<int> x = Array.Empty<int>().TakeThenSkip(2, 3);
        _ = new List<string> { "a", "b" }.TakeThenSkip(1, 0);
        _ = new double[] { 3.14, 2.71 }.TakeThenSkip(10, 100);
    }

    [Fact]
    public void Test1()
    {
        var source = new int[]{1,2,3,4,5};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.TakeThenSkip(0, 1));
    }
    
    [Fact]
    public void Test2()
    {
        var source = new int[]{1,2,3,4,5};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.TakeThenSkip(3, -1));
    }

    [Fact]
    public void Test3()
    {
        var source = Array.Empty<int>();
        var result = source.TakeThenSkip(2,3);
        Assert.Empty(result);
    }

    [Fact]
    public void Test4()
    {
        var source = new int[]{0,1,2,3,4,5,6,7,8,9};
        var result = source.TakeThenSkip(2,3);
        Assert.Equal(new[]{0,1,5,6}, result);
    }

    [Fact]
    public void Test5()
    {
        var source = new string[]{"qui","quo","qua"};
        var result = source.TakeThenSkip(1,0);
        Assert.Equal(new[]{"qui","quo","qua"}, result);
    }

    [Fact]
    public void Test6()
    {
        var source = new int[]{10,20,30,40,50};
        var result = source.TakeThenSkip(10,100);
        Assert.Equal(new[]{10,20,30,40,50}, result);
    }
}

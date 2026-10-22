namespace Esercizio2;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() {
        IEnumerable<int[]> x = Array.Empty<int>().Windowed(3);
        _ = new List<string> { "a", "b" }.Windowed(1);
        _ = new [] { 3.14, 2.71, 1.41 }.Windowed(2);
    }

    [Fact]
    public void Test1()
    {
        var source = Array.Empty<int>();
        var result = source.Windowed(3);
        Assert.Empty(result);
    }

    [Fact]
    public void Test2()
    {
        var source = new int[]{1,2,3,4};
        var result = source.Windowed(2).ToList();
        Assert.Equal(new[]{1,2}, result[0]);
        Assert.Equal(new[]{2,3}, result[1]);
        Assert.Equal(new[]{3,4}, result[2]);
    }

    [Fact]
    public void Test3()
    {
        var source = new int[]{1,2,3};
        var result = source.Windowed(3).ToList();
        Assert.Equal(new[]{1,2,3}, result[0]);
    }

    [Fact]
    public void Test4()
    {
        var source = new int[]{10,20};
        var result = source.Windowed(3).ToList();
        Assert.Empty(result);
    }

    [Fact]
    public void Test5()
    {
        var source = new string[]{"qui","quo","qua"};
        var result = source.Windowed(1).ToList();
        Assert.Equal(new[]{"qui"}, result[0]);
        Assert.Equal(new[]{"quo"}, result[1]);
        Assert.Equal(new[]{"qua"}, result[2]);
    }

    [Fact]
    public void test6()
    {
        var source = new int[]{1,2,3,4,5,6};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.Windowed(0));
    }

    [Fact]
    public void test7()
    {
        var source = new int[]{1,2,3,4,5,6};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.Windowed(-7));
    }
}

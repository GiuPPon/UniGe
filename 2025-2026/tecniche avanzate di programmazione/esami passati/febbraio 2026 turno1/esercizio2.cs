namespace Esercizio2;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() {
        IEnumerable<int[]> x = Array.Empty<int>().Slice(2);
        _ = new List<string> { "a" }.Slice(1);
    }

    [Fact]
    public void Test1()
    {
        var source = Array.Empty<int>();
        var result = source.Slice(3);
        Assert.Empty(result);
    }

    [Fact]
    public void Test2()
    {
        var source = new List<int>{1,2,3,4,5};
        var result = source.Slice(2).ToList();
        Assert.Equal(new[]{1,2}, result[0]);
        Assert.Equal(new[]{3,4}, result[1]);
        Assert.Equal(new[]{5}, result[2]);
    }

    [Fact]
    public void Test3()
    {
        var source = new List<int>{1,2,3};
        var result = source.Slice(3).ToList();
        Assert.Equal(new[]{1,2,3}, result[0]);
    }

    [Fact]
    public void Test4()
    {
        var source = new string[]{"qui","quo","qua"};
        var result = source.Slice(7).ToList();
        Assert.Equal(new[]{"qui","quo","qua"}, result[0]);
    }

    [Fact]
    public void Test5()
    {
        var source = new string[]{"qui","quo","qua"};
        var result = source.Slice(1).ToList();
        Assert.Equal(new[]{"qui"}, result[0]);
        Assert.Equal(new[]{"quo"}, result[1]);
        Assert.Equal(new[]{"qua"}, result[2]);
    }

    [Fact]
    public void Test6()
    {
        var source = new string[]{"qui","quo","qua"};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.Slice(-123));
    }
}

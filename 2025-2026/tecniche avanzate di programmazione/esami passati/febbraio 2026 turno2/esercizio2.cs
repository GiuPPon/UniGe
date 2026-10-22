namespace Esercizio2;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() {
        IEnumerable<int> x = Array.Empty<int>().LimitConsecutive(2, null);
        new List<string> { "a" }.LimitConsecutive(1,StringComparer.Ordinal);
    }
    [Fact]
    public void Test1()
    {
        var source = new int[]{1,2,3};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.LimitConsecutive(0, null));
    }

    [Fact]
    public void Test2()
    {
        var source = new int[]{42};
        var result = source.LimitConsecutive(2, null);
        Assert.Equal(new[]{42}, result);
    }

    [Fact]
    public void Test3()
    {
        var source = new int[]{1,1,1,2,2};
        var result = source.LimitConsecutive(2, null);
        Assert.Equal(new[]{1,1,2,2}, result);
    }

    [Fact]
    public void Test4()
    {
        var source = new int[]{1,1,3,1,1};
        var result = source.LimitConsecutive(1, null);
        Assert.Equal(new[]{1,3,1}, result);
    }

    [Fact]
    public void Test5()
    {
        var source = new List<string>{"qui","quo","quo","qua"};
        var result = source.LimitConsecutive(1, null);
        Assert.Equal(new[]{"qui","quo","qua"}, result);
    }

    [Fact]
    public void Test6()
    {
        var source = new List<string>{"a","A","a"};
        var result = source.LimitConsecutive(1, StringComparer.OrdinalIgnoreCase);
        Assert.Single(result);
    }
}

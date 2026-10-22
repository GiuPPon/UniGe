namespace Esercizio2;
using Esercizio1;

public class UnitTest1
{
    
    [Fact]
    public void SanityCheck() {
        _ = Array.Empty<int>().EveryN(123);
        _ = new string [] { "ciao" }.EveryN(27);
    }

    [Fact]
    public void Test1()
    {
        var source = new int[]{1,2,3,4};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.EveryN(0));
    }

    [Fact]
    public void Test2()
    {
        var source = new int[]{1,2,3,4};
        Assert.Throws<ArgumentOutOfRangeException>(() => source.EveryN(-101));
    }

    [Fact]
    public void Test3()
    {
        var source = new string[]{"qui","quo","qua"};
        var result = source.EveryN(1);
        Assert.Equal(new[]{"qui","quo","qua"}, result);
    }

    [Fact]
    public void Test4()
    {
        var source = new int[]{800, 123, 900, -1, 700};
        var result = source.EveryN(2);
        Assert.Equal(new[]{800, 900, 700}, result);
    }
}

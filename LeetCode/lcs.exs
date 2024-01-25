ExUnit.start()

defmodule Solution do
  @spec longest_common_subsequence(text1 :: String.t, text2 :: String.t) :: integer
  def longest_common_subsequence(text1, text2) do
    lcs(text1, text2, 0, 0)
  end

  defp equal_chars(text1, text2, ptr_1, ptr_2) do
    char1 = String.at(text1, ptr_1)
    char2 = String.at(text2, ptr_2)

    char1 == char2
  end

  defp lcs(text1, text2, ptr1, ptr2) do
    if ptr1 == String.length(text1) or ptr2 == String.length(text2) do
      0
    else
      if equal_chars(text1, text2, ptr1, ptr2) do
        lcs(text1, text2, ptr1 + 1, ptr2 + 1) + 1
      else
        max(
          lcs(text1, text2, ptr1 + 1, ptr2),
          lcs(text1, text2, ptr1, ptr2 + 1)
        )
      end
    end
  end
end

defmodule SolutionTest do
  use ExUnit.Case

  test "longest common subsequence of empty strings" do
    assert Solution.longest_common_subsequence("", "") == 0
  end

  test "longest common subsequence of 'abc' and 'ac'" do
    assert Solution.longest_common_subsequence("abc", "ac") == 2
  end

  test "longest common subsequence of non-overlapping strings" do
    assert Solution.longest_common_subsequence("abc", "def") == 0
  end

  test "longest common subsequence of 'abcde' and 'ace'" do
    assert Solution.longest_common_subsequence("abcde", "ace") == 3
  end

  test "longest common subsequence of 'bsbininm' and 'jmjkbkjkv'" do
    assert Solution.longest_common_subsequence("bsbininm", "jmjkbkjkv") == 1
  end

end

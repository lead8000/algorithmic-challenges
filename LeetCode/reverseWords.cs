// 1/10/2023

public class Solution {
    public string ReverseWords(string s) {
        var words = s.Split(' ');
        string result = "";
        for (int j = 0; j < words.Length; j++)
        {
            string reverse = "";
            for (int i = 0; i < words[j].Length; i++)
            {
                reverse = words[j][i] + reverse;
            }
            result += reverse;
            if (2*j + 1 < 2*words.Length-1)
                result += " ";
        }
        return result;
    }
}
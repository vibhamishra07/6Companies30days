// Problem 03:- Bulss and Cows

// Approach:-
// ->For Bulls count: Traverse the whole guess string and check if guess character at index (i)
//  is matched with secret character at that index (i) then increase the count of [bulls].
// Else if not matched then store that index (i) in vector which is not matched for recalling.
// And increase the count of that characters in an unordered map for cows count.

// ->For cows count: Traverse the vector v which stores the indexes of that character which is not
//  matched and then check whether that character is present in secret by checking if smp map is not 0
//  at that character.
// example: if smp['1']==0, then it means there is no left character in secret string which is equal.
// and if smp['1']>0, then it means the secret string have some characters for cows count. and then 
// increase the count of [cows].




string getHint(string secret, string guess)
{
    int slen = secret.length(), glen = guess.length(), bulls = 0, cows = 0;
    vector<int> v;
    unordered_map<char, int> smp;
    for (int i = 0; i < slen; i++)
    {
        if (guess[i] == secret[i])
        {
            bulls++;
        }
        else
        {
            v.push_back(i);
            smp[secret[i]]++;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (smp[guess[v[i]]])
        {
            cows++;
            smp[guess[v[i]]]--;
        }
    }
    string str = to_string(bulls) + "A" + to_string(cows) + "B";

    return str;
}
class Solution {
public:
    const long long LIM = 1000001;
    vector<int> primes;

    void sieve() {
        vector<bool> isPrime(5001, true);
        for (int i = 2; i * i <= 5000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 5000; j += i)
                    isPrime[j] = false;
            }
        }
        for (int i = 2; i <= 5000; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    int powerInFact(int n, int p) {
        int cnt = 0;
        while (n) {
            n /= p;
            cnt += n;
        }
        return cnt;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int p : primes) {
            if (p > n) break;

            int e = powerInFact(n, p) -
                    powerInFact(r, p) -
                    powerInFact(n - r, p);

            while (e--) {
                if (ans > LIM / p) return LIM;
                ans *= p;
            }
        }

        return min(ans, LIM);
    }

    long long countPerm(vector<int>& cnt) {
        int total = 0;
        long long ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            long long cur = nCr(total + x, x);

            if (ways >= LIM || cur >= LIM) return LIM;
            if (ways > LIM / cur) return LIM;

            ways *= cur;
            total += x;
        }

        return min(ways, LIM);
    }

    string smallestPalindrome(string s, int k) {
        sieve();

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countPerm(half) < k)
            return "";

        string left = "";
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countPerm(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
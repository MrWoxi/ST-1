// Copyright 2026 Klimovich V.O.
#include <gtest/gtest.h>
#include <cstdint>

bool checkPrime(uint64_t value);
uint64_t nPrime(uint64_t n);
uint64_t nextPrime(uint64_t value);
uint64_t sumPrime(uint64_t hbound);

TEST(CheckPrimeTest, ZeroAndOne) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrimeTest, PrimeTwo) {
    EXPECT_TRUE(checkPrime(2));
}

TEST(CheckPrimeTest, SmallPrimes) {
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
}

TEST(CheckPrimeTest, EvenComposites) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(100));
}

TEST(CheckPrimeTest, OddComposites) {
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(15));
    EXPECT_FALSE(checkPrime(21));
    EXPECT_FALSE(checkPrime(49));
}

TEST(NPrimeTest, ZeroInput) {
    EXPECT_EQ(nPrime(0), 0);
}

TEST(NPrimeTest, FirstPrime) {
    EXPECT_EQ(nPrime(1), 2);
}

TEST(NPrimeTest, FirstFew) {
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
}

TEST(NPrimeTest, TenthPrime) {
    EXPECT_EQ(nPrime(10), 29);
}

TEST(NextPrimeTest, FromComposite) {
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(6), 7);
    EXPECT_EQ(nextPrime(8), 11);
}

TEST(NextPrimeTest, FromPrime) {
    EXPECT_EQ(nextPrime(11), 13);
    EXPECT_EQ(nextPrime(17), 19);
}

TEST(NextPrimeTest, SmallValues) {
    EXPECT_EQ(nextPrime(0), 2);
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
}

TEST(SumPrimeTest, EmptyRange) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
    EXPECT_EQ(sumPrime(2), 0);
}

TEST(SumPrimeTest, UpToTen) {
    EXPECT_EQ(sumPrime(10), 17);
}

TEST(SumPrimeTest, UpToTwenty) {
    EXPECT_EQ(sumPrime(20), 77);
}

TEST(SumPrimeTest, UpToOneHundred) {
    EXPECT_EQ(sumPrime(100), 1060);
}

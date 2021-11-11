#pragma once 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using BIG_INT = unsigned long long int;

class SHA384
{
public:
    BIG_INT h0 = 0xCBBB9D5DC1059ED8;
    BIG_INT h1 = 0x629A292A367CD507;
    BIG_INT h2 = 0x9159015A3070DD17;
    BIG_INT h3 = 0x152FECD8F70E5939;
    BIG_INT h4 = 0x67332667FFC00B31;
    BIG_INT h5 = 0x8EB44A8768581511;
    BIG_INT h6 = 0xDB0C2E0D64F98FA7;
    BIG_INT h7 = 0x47B5481DBEFA4FA4;

    std::vector<BIG_INT> constantTable
    { 
        0x428A2F98D728AE22, 0x7137449123EF65CD, 0xB5C0FBCFEC4D3B2F, 0xE9B5DBA58189DBBC,
        0x3956C25BF348B538, 0x59F111F1B605D019, 0x923F82A4AF194F9B, 0xAB1C5ED5DA6D8118,
        0xD807AA98A3030242, 0x12835B0145706FBE, 0x243185BE4EE4B28C, 0x550C7DC3D5FFB4E2,
        0x72BE5D74F27B896F, 0x80DEB1FE3B1696B1, 0x9BDC06A725C71235, 0xC19BF174CF692694,
        0xE49B69C19EF14AD2, 0xEFBE4786384F25E3, 0x0FC19DC68B8CD5B5, 0x240CA1CC77AC9C65,
        0x2DE92C6F592B0275, 0x4A7484AA6EA6E483, 0x5CB0A9DCBD41FBD4, 0x76F988DA831153B5,
        0x983E5152EE66DFAB, 0xA831C66D2DB43210, 0xB00327C898FB213F, 0xBF597FC7BEEF0EE4,
        0xC6E00BF33DA88FC2, 0xD5A79147930AA725, 0x06CA6351E003826F, 0x142929670A0E6E70,
        0x27B70A8546D22FFC, 0x2E1B21385C26C926, 0x4D2C6DFC5AC42AED, 0x53380D139D95B3DF,
        0x650A73548BAF63DE, 0x766A0ABB3C77B2A8, 0x81C2C92E47EDAEE6, 0x92722C851482353B,
        0xA2BFE8A14CF10364, 0xA81A664BBC423001, 0xC24B8B70D0F89791, 0xC76C51A30654BE30,
        0xD192E819D6EF5218, 0xD69906245565A910, 0xF40E35855771202A, 0x106AA07032BBD1B8,
        0x19A4C116B8D2D0C8, 0x1E376C085141AB53, 0x2748774CDF8EEB99, 0x34B0BCB5E19B48A8,
        0x391C0CB3C5C95A63, 0x4ED8AA4AE3418ACB, 0x5B9CCA4F7763E373, 0x682E6FF3D6B2B8A3,
        0x748F82EE5DEFB2FC, 0x78A5636F43172F60, 0x84C87814A1F0AB72, 0x8CC702081A6439EC,
        0x90BEFFFA23631E28, 0xA4506CEBDE82BDE9, 0xBEF9A3F7B2C67915, 0xC67178F2E372532B,
        0xCA273ECEEA26619C, 0xD186B8C721C0C207, 0xEADA7DD6CDE0EB1E, 0xF57D4F7FEE6ED178,
        0x06F067AA72176FBA, 0x0A637DC5A2C898A6, 0x113F9804BEF90DAE, 0x1B710B35131C471B,
        0x28DB77F523047D84, 0x32CAAB7B40C72493, 0x3C9EBE0A15C9BEBC, 0x431D67C49C100D4C,
        0x4CC5D4BECB3E42B6, 0x597F299CFC657E2A, 0x5FCB6FAB3AD6FAEC, 0x6C44198C4A475817
    };

    std::string message = "helloworldlalaland";
    std::vector<bool> binMessage;
    std::vector<std::vector<bool>> chunks1024;
    std::vector<BIG_INT> chunks64;

    int L;
    int K;

    void messageToBinary()
    {
        for (int i = 0; i <= message.length(); i++)
        {
            int val = static_cast<int>(message[i]);

            std::vector<bool> bin;
            while (val > 0)
            {
                (val % 2)? bin.push_back(1) :
                    bin.push_back(0);
                val /= 2;
            }
            std::reverse(bin.begin(), bin.end());
            while(bin.size() % 8 != 0)
                bin.insert(bin.begin(), 0);

            binMessage.insert(binMessage.end(), bin.begin(), bin.end());
        }

    }

    BIG_INT fromBinToDec(std::vector<bool> vec)
    {
        BIG_INT result = 0;

        for(auto v : vec)
        {
            result |= v;
            result <<= 1;
        }

        return result/2;
    }

    void break1024ChunksTo64()
    {
        int start = 0;
        int end = 63;

        for (auto chunks : chunks1024)
            for(int i = 0; i < 16; i++)
            {
                std::vector<bool> chunk(chunks.begin() + start, chunks.begin() + end);
                chunks64.push_back(fromBinToDec(chunk));

                start += 64;
                end   += 64;
            }
    }

    std::vector<bool> fromDecToBigEndian128(int n)
    {
        std::vector<bool> bin;
        int i = 0;
        while (n > 0) 
        {
            bin.push_back(n % 2);
            n = n / 2;
            i++;
        }
        if(bin.size() < 128){
            int diff = 128 - bin.size();
            bin.insert(bin.begin(), diff, 0);
        }

        return bin;
    }

    void countK()
    {
        K = 0;
        while ((L + 1 + K) % 896 != 0) 
            K++;
    }

    void paddingMessage()
    {
        countK();

        binMessage.push_back(1);
        binMessage.insert(binMessage.end(), K, 0);
        auto bigEndian = fromDecToBigEndian128(L);
        std::cout << "\n";
        binMessage.insert(binMessage.end(), bigEndian.begin(), bigEndian.end());
    }

    void breakMessageToChunks1024()
    {
        std::vector<bool> chunk;
        for(int i = 0; i < binMessage.size(); i++)
        {
            chunk.push_back(binMessage[i]); 
            if ((i + 1) % 1024 == 0)
            {
                chunks1024.push_back(chunk);
                chunk.clear();
            }       
        }
    }

    BIG_INT rightRotate(BIG_INT i, int n)
    {
        return (n >> i) | (n << (64 - i));
    }

    BIG_INT rightShift(BIG_INT i, int n)
    {
        return i >> n;
    }

    void extendChunks64()
    {
        for(int i = 15; i < 80; i++)
        {
            BIG_INT s0 = (rightRotate(chunks64[i - 14], 1) ^ rightRotate(chunks64[i - 14], 8) ^ rightShift(chunks64[i - 14], 7));
            BIG_INT s1 = (rightRotate(chunks64[i - 1], 19) ^ rightRotate(chunks64[i - 1], 61) ^ rightShift(chunks64[i - 1], 6));
            chunks64[i] = chunks64[i - 15] + s0 + chunks64[i - 6] + s1;
        }
    }

    void mainCycle()
    {
        BIG_INT a = h0;
        BIG_INT b = h1;
        BIG_INT c = h2;
        BIG_INT d = h3;
        BIG_INT e = h4;
        BIG_INT f = h5;
        BIG_INT g = h6;
        BIG_INT h = h7;

        for(int i = 0; i < 80; i++)
        {
            BIG_INT s1 = (rightRotate(e, 14) ^ rightRotate(e, 18) ^ rightRotate (e, 41));
            BIG_INT ch = (e & f) ^ ((!e) & g);
            BIG_INT temp1 = h + s1 + ch + binMessage[i] + chunks64[i];
            BIG_INT s0 = (rightRotate(a, 28) ^ rightRotate(a, 34) ^ rightRotate(a, 39));
            BIG_INT maj = (a & b) ^ (a & c) ^ (b & c);
            BIG_INT temp2 = s0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h0 = h0 + a;
        h1 = h1 + b;
        h2 = h2 + c;
        h3 = h3 + d;
        h4 = h4 + e;
        h5 = h5 + f;
        h6 = h6 + g;
        h7 = h7 + h;
    }

    void hash()
    {
        messageToBinary();
        L = binMessage.size();

        paddingMessage();
        breakMessageToChunks1024();
        break1024ChunksTo64();
        extendChunks64();
        mainCycle();

        std::cout << std::hex << std::uppercase 
            << h0 << " " << h1 << " " << h2 << " " << h3 << " " 
            << h4 << " " << h5 << " " << h6 << " " << h7 << "\n\n";


    }

    SHA384(){};







};
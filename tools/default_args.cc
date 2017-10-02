// Copyright 2013-2017 Edgar Costa
// See LICENSE file for license details.
//
// checks that the charpoly is the same if we change variables

#include <sstream>

#include<NTL/vector.h>

//we can do this much better..... see toric code
void default_args(int64_t &precision, NTL::Vec<int64_t> &N, NTL::Vec<int64_t> &charpoly_prec, const int64_t &p, const int64_t &n, const int64_t &d)
{
    std::stringstream buffer;
    if ( n == 2 && d == 3 ) {
		if ( p < 5) {
			precision = 5;
			buffer << "[2 3]\n[2 2 2]";
		} else if ( 5 <= p && p < 17 ) {
			precision = 3;
			buffer << "[2 2]\n[2 2 2]";
		} else if ( 17 <= p  ) {
			precision = 1;
			buffer << "[0 1]\n[3 1 1]";
        }
	} else if ( n == 2 && d == 4 ) {
		if ( p < 5) {
			precision = 7;
			buffer << "[4 4]\n[5 4 3 3 3 3 3]";
		} else if ( 5 <= p && p < 17 ) {
			precision = 5;
			buffer << "[3 3]\n[5 4 3 3 3 3 3]";
		} else if ( 17 <= p  ) {
			precision = 3;
			buffer << "[2 2]\n[4 3 2 2 2 2 2]";
        }
	} else if ( n == 2 && d == 5 ) {
		if ( p < 5) {
			precision = 12;
			buffer << "[6 6]\n[10 9 8 7 6 5 5 5 5 5 5 5 5]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 9;
			buffer << "[4 5]\n[9 8 7 6 5 4 4 4 4 4 4 4 4]";
		} else if ( 7 <= p  ) {
			precision = 7;
			buffer << "[4 4]\n[9 8 7 6 5 4 4 4 4 4 4 4 4]";
        }
    } else if ( n == 2 && d == 6 ) {
		if ( p < 5) {
			precision = 19;
			buffer << "[8 9]\n[16 15 14 13 12 11 10 9 8 7 7 7 7 7 7 7 7 7 7 7 7]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 13;
			buffer << "[7 7]\n[15 14 13 12 11 10 9 8 7 6 6 6 6 6 6 6 6 6 6 6 6]";
		} else if ( 7 <= p && p < 11 ) {
			precision = 13;
			buffer << "[6 7]\n[15 14 13 12 11 10 9 8 7 6 6 6 6 6 6 6 6 6 6 6 6]";
		} else if ( 11 <= p  ) {
			precision = 11;
			buffer << "[6 6]\n[15 14 13 12 11 10 9 8 7 6 6 6 6 6 6 6 6 6 6 6 6]";
	} else if ( n == 2 && d == 7 ) {
		if ( p < 5) {
			precision = 23;
			buffer << "[11 11]\n[23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 20;
			buffer << "[10 10]\n[23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9]";
		} else if ( 7 <= p && p < 11 ) {
			precision = 19;
			buffer << "[10 10]\n[23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9]";
		} else if ( 11 <= p && p < 17 ) {
			precision = 17;
			buffer << "[9 9]\n[23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9]";
		} else if ( 17 <= p  ) {
			precision = 15;
			buffer << "[8 8]\n[22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8]";
	} else if ( n == 2 && d == 8 ) {
		if ( p < 5) {
			precision = 30;
			buffer << "[14 14]\n[32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 26;
			buffer << "[13 13]\n[32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 7 <= p && p < 13 ) {
			precision = 25;
			buffer << "[13 13]\n[32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 13 <= p && p < 17 ) {
			precision = 25;
			buffer << "[12 13]\n[32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 17 <= p  ) {
			precision = 21;
			buffer << "[11 11]\n[31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11]";
	} else if ( n == 2 && d == 9 ) {
		if ( p < 5) {
			precision = 41;
			buffer << "[18 18]\n[43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 33;
			buffer << "[16 16]\n[42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15]";
		} else if ( 7 <= p && p < 11 ) {
			precision = 32;
			buffer << "[16 16]\n[42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15]";
		} else if ( 11 <= p && p < 17 ) {
			precision = 31;
			buffer << "[16 16]\n[42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15]";
		} else if ( 17 <= p  ) {
			precision = 29;
			buffer << "[15 15]\n[42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15]";
        }
	} else if ( n == 3 && d == 4 ) {
		if ( p < 5) {
			precision = 16;
			buffer << "[7 7 8]\n[24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 5 5]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 9;
			buffer << "[4 5 5]\n[23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 4 4]";
		} else if ( 7 <= p && p < 23 ) {
			precision = 6;
			buffer << "[4 4 3]\n[23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 3]";
		} else if ( 23 <= p && p < 43 ) {
			precision = 5;
			buffer << "[3 3 3]\n[22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 3 3]";
		} else if ( 43 <= p  ) {
			precision = 4;
			buffer << "[3 3 2]\n[22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 2]";
        }
	} else if ( n == 3 && d == 5 ) {
		if ( p < 5) {
			precision = 21;
			buffer << "[11 11 10]\n[58 56 54 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 7 7 7 7]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 17;
			buffer << "[8 8 9]\n[57 55 53 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 7 7 7 7 7]";
		} else if ( 7 <= p && p < 11 ) {
			precision = 14;
			buffer << "[8 8 7]\n[57 55 53 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 6 6 6 6]";
		} else if ( 11 <= p && p < 23 ) {
			precision = 12;
			buffer << "[7 7 6]\n[57 55 53 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 6 6 6 6]";
		} else if ( 23 <= p && p < 29 ) {
			precision = 11;
			buffer << "[6 6 6]\n[56 54 52 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 6 6 6 6 6]";
		} else if ( 29 <= p  ) {
			precision = 10;
			buffer << "[6 6 5]\n[56 54 52 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 5 5 5 5]";
        }
    } else if ( n == 3 && d == 6 ) {
		if ( p < 5) {
			precision = 38;
			buffer << "[17 18 17]\n[117 115 113 111 109 107 105 103 101 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 13 13 13 13 13 13 13 13 13 13]";
		} else if ( 5 <= p && p < 7 ) {
			precision = 29;
			buffer << "[15 15 14]\n[116 114 112 110 108 106 104 102 100 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 7 <= p && p < 11 ) {
			precision = 28;
			buffer << "[15 15 14]\n[116 114 112 110 108 106 104 102 100 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 11 <= p && p < 17 ) {
			precision = 26;
			buffer << "[14 14 13]\n[116 114 112 110 108 106 104 102 100 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 17 <= p && p < 23 ) {
			precision = 24;
			buffer << "[13 13 12]\n[116 114 112 110 108 106 104 102 100 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 12 12 12 12 12 12 12 12 12 12]";
		} else if ( 23 <= p  ) {
			precision = 22;
			buffer << "[12 12 11]\n[115 113 111 109 107 105 103 101 99 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 11 11 11 11 11 11 11 11 11 11]";
	} else {
        using namespace std;
        cout << "I'm sorry. We don't have the precomputed values of working precision and N for n = "<<n<<"d = "<< d <<endl;
        cout << "Please email \"Edgar Costa\" <edgarcosta@math.dartmouth.edu>" << endl;
        abort();
    }
    buffer >> N;
    buffer >> charpoly_prec;
}


/*
 * I have manually fixed n = 2 and d == 3
def default_args(n, d):
    p = 2;
    old_pfz = None;
    old_p = None;
    output = "";
    output +="\tif ( n == %d && d == %d ) {\n" % (n, d)
    while p <= 43:
        p = next_prime(p);
        if p == 3:
            pfz = precision_for_zeta(n, d, p, bound = 3)[-1]
        else:
            pfz = precision_for_zeta(n, d, p)[-1]
        #print p, pfz
        if old_pfz is None:
            old_pfz = pfz
        if pfz != old_pfz:
            if old_p is None:
                output += "\t\tif ( p < %d) {\n" % p
            else:
                output += "\t\t} else if ( %d <= p && p < %d ) {\n" % (old_p, p,)
            
            output += "\t\t\tprecision = %d;\n" % old_pfz[1]
            old_pfz[-1][-1] = old_pfz[-1][-2];
            output += '\t\t\tbuffer << \"%s\\n%s\";\n' % (str(old_pfz[3]).replace(",", ""), str(old_pfz[-1]).replace(",", ""))
            old_pfz = pfz
            old_p = p
    output += "\t\t} else if ( %d <= p  ) {\n" % (old_p,)
    output += "\t\t\tprecision = %d;\n" % old_pfz[1]
    old_pfz[-1][-1] = old_pfz[-1][-2];
    output += '\t\t\tbuffer << \"%s\\n%s\";\n' % (str(old_pfz[3]).replace(",", ""), str(old_pfz[-1]).replace(",", ""))
    output += "\t}"
    print output
for n in range(2,4):
    for d in range(n + 1,6):
        default_args(n, d)
*/

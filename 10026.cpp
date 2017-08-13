/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 10026 - Shoemaker's Problem
 * Fecha: 30-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Job
{
    int id;
    int time;
    int fine;
};

bool compare(const Job &src1, const Job&src2)
{
    double c1 = (double)src1.fine/src1.time;
    double c2 = (double)src2.fine/src2.time;
    if (c1 != c2) return c1 > c2;
    return src1.id < src2.id;
}

int n, i, j, cases;
int main(int argc, char const *argv[])
{
    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
        scanf("%d", &n);
        vector<Job> jobs(n);
        for (j = 0; j < n; j++) {
            scanf("%d %d", &jobs[j].time, &jobs[j].fine);
            jobs[j].id = j+1;
        }

        sort(jobs.begin(), jobs.end(), compare);
        for (j = 0; j < n; j++) {
            printf("%d", jobs[j].id);
            if (j != n-1) printf(" ");
        }
        printf("\n");
        if (i != cases-1) printf("\n");
    }
}

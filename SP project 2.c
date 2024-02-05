#include <stdio.h>

struct Node
{
    int nodeid;
    int adjcount;
    int adjs[10];
    int costs[10];
};

int addNode (struct Node * p, int nid, int count)
{
    int i =0, ncount = count;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid) { break; }
    }
    if (i == count)
    {
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent (struct Node *p, int nid1, int nid2, int cost, int count)
{
    int i =0, index;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid1)
        {
            int c = p[i].adjcount;
            p[i].adjs[c] = nid2;
            p[i].costs[c] = cost;
            p[i].adjcount = c+1;

            break;
        }
    }
}

void findTriangle(struct Node *p,int nodecount)
{
    int  trianglecount = 0;
    for (int i=0; i<nodecount; i++) // akta node nilam(p[i])
    {
        for(int j=i+1; j<nodecount; j++) // arekta node nilam(p[j])
        {
            for(int k=j+1; k<nodecount; k++) // arekta nilam(total 3 ta)(p[k])
            {
                int flag = 0, flag1 = 0, flag2 = 0;

                for(int l=0; l<p[i].adjcount; l++) // i,j adjacent ki na
                {
                    if(p[i].adjs[l] == p[j].nodeid)
                    {
                        flag = 1;
                        break;
                    }
                }
                for(int m=0; m<p[j].adjcount; m++) //j,k adjacent ki na
                {
                    if(p[j].adjs[m] == p[k].nodeid)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                for(int n=0; n<p[i].adjcount; n++) // i,k adjacent ki na
                {
                    if(p[i].adjs[n] == p[k].nodeid)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if(flag == 1 && flag1 == 1 && flag2 == 1) // 3 ta adjacent hole triangle hbe , oigula print korbo, triangle count barabo
                {
                    trianglecount++;
                    printf("\nTriangle: %d %d %d", p[i].nodeid, p[j].nodeid, p[k].nodeid);
                }
            }
        }
    }
    printf("\nTotal triangle = %d\n",trianglecount);
}


int main() {

    struct Node nodes[50];
    int nodecount = 0;
    int n1=0, n2=0, c = 0;

    while (1)
    {
        printf ("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c== -9) {break;}
        nodecount = addNode (nodes, n1, nodecount);
        nodecount = addNode (nodes, n2, nodecount);

        addAdjacent (nodes, n1, n2, c, nodecount);
        addAdjacent (nodes, n2, n1, c, nodecount);
    }

    findTriangle(nodes,nodecount);

    return 0;
}

#include<stdio.h>
#include<math.h>
typedef struct {
 float x,y;
}vertex;

typedef struct {
 float area;
 float length;
 float breath;
 vertex v[3];
}rectangle;

rectangle input_rectangle()
{
 rectangle r ;
 printf("Enter the vertices of the rectangle:\n ");
 scanf("%f%f%f%f%f%f",&r.v[0].x,&r.v[0].y,&r.v[1].x,&r.v[1].y,&r.v[2].x,&r.v[2].y);
 return r;
}
void input_n_rectangles(int n,rectangle ar[n])
{
 for(int i=0;i<n;i++)
 { 
  ar[i]=input_rectangle();
 }
}
void compute_rectangle(rectangle *pr)
{
 pr->length =sqrt(pow(pr->v[0].x-pr->v[1].x,2)+pow(pr->v[0].y-pr->v[1].y,2));
 pr->breath=sqrt(pow(pr->v[1].x-pr->v[2].x,2)+pow(pr->v[1].y-pr->v[2].y,2));
 pr->area= pr->length* pr->breath;
}
void compute_n_rectangle(int n,rectangle ar[n])
{
 for(int i=0;i<n;i++)
 {
  compute_rectangle(&ar[i]);
 }
}

void output_rectangle(rectangle r)
{
 printf("(%f %f),(%f %f), (%f %f) is %f ",r.v[0].x,r.v[0].y,r.v[1].x,r.v[1].y,r.v[2].x,r.v[2].y,r.area);
}

void output_n_rectangles(int n,rectangle ar[n])
{
 for(int i=0;i<n;i++)
 { 
  output_rectangle(ar[i]);
 }
}

int main()
{
 int n;
 printf("Enter the number of rectangles:");
 scanf("%d",&n);
 rectangle ar[n];
 input_n_rectangles(n,ar);
 compute_n_rectangles(n,ar);
 output_n_rectangles(n,ar);
 return 0;
}

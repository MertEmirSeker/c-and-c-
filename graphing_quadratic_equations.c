#include <stdio.h>

double drawing_the_graph(int y, int a, int b, int c) // drawing function
{
    return (y * y * a + y * b + c);
}

int main()
{

    for (;;) // our infinite loop
    {
        int i, a, b, c;
        printf("Select an operation\n");
        printf("0 -> Enter the coefficients.\n");
        printf("1 -> Draw the graph.\n");
        printf("2 -> Print the graph into a graph.txt file.\n");
        printf("3 -> Exit.\n");
        printf("Choice:");
        scanf("%d", &i);

        if (i == 0)
        {
            printf("Please enter the coefficient for the following equation : x = a*(y*y) + b*y + c\n");

            printf("a:"); // entering the coefficients
            scanf("%d", &a);
            printf("b:");
            scanf("%d", &b);
            printf("c:");
            scanf("%d", &c);

            FILE *fp;
            fp = fopen("coefficients.txt", "w"); // writing coefficients to file
            fprintf(fp, "%d\n%d\n%d\n", a, b, c);
            fclose(fp);

            printf("coefficients.txt file has been created.\n");
        }

        if (i == 1)
        {

            int e, g;
            int x_axis_ind = -50;
            FILE *fp;
            fp = fopen("coefficients.txt", "r"); // reading the coefficients
            fscanf(fp, "%d\n%d\n%d", &a, &b, &c);

            for (e = 15; e > -16; --e) // e ---> y axis   g----> x axis
            {
                for (g = -55; g < 56; ++g)
                {
                    if (drawing_the_graph(e, a, b, c) == g) // drawing the graph
                    {
                        if (e == -1)
                        {

                            printf("\b#");
                        }
                        else
                        {
                            printf("#");
                        }
                    }
                    else if (e == -1 && ((g > 0 && g % 10 == 7) || (g < 0 && g % 10 == -3)))
                    {
                        printf("%d", x_axis_ind); // writing x axis values
                        x_axis_ind += 10;
                        if (x_axis_ind < 0)
                        {
                            g += 2;
                        }
                        else if (x_axis_ind > 0)
                        {
                            g++;
                        }
                    }

                    else if (g == -1 && e == -1)
                    {
                        printf("|");
                    }
                    else if (g == 0 && e == -1)
                    {
                        printf(" ");
                    }
                    else if (g == 0) // drawing x axis
                    {
                        printf("|");
                    }
                    else if (e == 0) // drawing y axis
                    {
                        printf("-");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }

        if (i == 2)
        {
            int e, g;
            FILE *fp;
            fp = fopen("coefficients.txt", "r"); // reading the entered values from file
            fscanf(fp, "%d\n%d\n%d", &a, &b, &c);
            fp = fopen("graph.txt", "w"); // writing the graph.txt file
            for (e = 15; e > -16; --e)
            {
                for (g = -55; g < 56; ++g)
                {
                    if (drawing_the_graph(e, a, b, c) == g)
                    {
                        fprintf(fp, "%s", "#");
                    }

                    else if (g == 0)
                    {
                        fprintf(fp, "%s", "|");
                    }
                    else if (e == 0)
                    {
                        fprintf(fp, "%s", "-");
                    }
                    else
                    {
                        fprintf(fp, "%s", " ");
                    }
                }
                fprintf(fp, "%s", "\n");
            }
            fclose(fp);
        }
        if (i == 3) // to exit infinite loop
        {
            return 0;
        }
    }
    return 0;
}
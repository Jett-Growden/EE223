/*
 * Name: Jett Growden
 * Description: P3
 * Date Assigned: 09-18-2023
 * Date Due: 09-25-2023
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int circle_3D_v2(double radius, double length);
int annulus_3D_v2(double radius_outer, double radius_inner, double length);
int rectangle_filled_3D_v2(double base, double height, double length);
int rectangle_hollow_3D_v2(double base_outer, double height_outer, double base_inner, double height_inner, double length);
void help(void); //manage our help.

int main(int argc, char** argv) {
    int index;
    printf("Count &d\n",argc); //count of arguments
    
    for(index =0; index < argc; index++){
        printf("argv{ %d}: %s\n",index, argv[index]); //displays each argument
    }
    
    if (argc <= 1 ){
        help(); //implicitly call help in case user did not know what they were doing.
    } else if(strcmpi( argv [ 1 ], "/h") == 0){
        help();
    } else if(strcmpi( argv [ 1 ], "/?") == 0){
        help();
    } else if (( argc >= 3) && ( strcmpi( argv[ 1 ], "/Circle") == 0) && ( strcmpi ( argv[ 2 ], "/i") == 0)) {
            double r;
            double l;
        
        printf("Please Enter a Radius (in): \n");
        scanf("%lf", &r );
    
        printf("Please Enter Length (in): \n");
        scanf("%lf", &l );
        
        circle_3D_v2(r,l);
        
    } else if (( argc >= 3) && ( strcmpi( argv[ 1 ], "/Annulus") == 0) && ( strcmpi ( argv[ 2 ], "/i") == 0)) {
        double radius_outer;
        double radius_inner;
        double length;
        
        printf("Please Enter a Radius (Outer) (in): \n");
        scanf("%lf", &radius_outer);
    
        printf("Please Enter a Radius (Inner): \n");
        scanf("%lf", &radius_inner);
    
        printf("Please Enter Length (in): \n");
        scanf("%lf", &length );

        
        annulus_3D_v2(radius_outer, radius_inner, length);
        
    } else if (( argc >= 3) && ( strcmpi( argv[ 1 ], "/RF") == 0) && ( strcmpi ( argv[ 2 ], "/i") == 0)) {
        double base;
        double height;
        double length;
        
        
        printf("Please Enter a Base (in): \n");
        scanf("%lf", &base);
    
        printf("Please Enter a Height (in): \n");
        scanf("%lf", &height);
    
        printf("Please Enter Length (in): \n");
        scanf("%lf", &length );
        
        rectangle_filled_3D_v2( base,  height,  length);
        
        
    } else if (( argc >= 3) && ( strcmpi( argv[ 1 ], "/RH") == 0) && ( strcmpi ( argv[ 2 ], "/i") == 0)) {
        double base_outer;
        double height_outer;
        double base_inner;
        double height_inner;
        double length;
        
        printf("Please Enter a Outer Base (in): \n");
        scanf("%lf", &base_outer);
    
        printf("Please Enter a Outer Height (in): \n");
        scanf("%lf", &height_outer);
    
        printf("Please Enter Inner Base (in): \n");
        scanf("%lf", &base_inner );
    
        printf("Please Enter Inner Height (in): \n");
        scanf("%lf", &height_inner );
    
        printf("Please Enter Length (in): \n");
        scanf("%lf", &length );
        
        rectangle_hollow_3D_v2( base_outer,  height_outer,  base_inner,  height_inner,  length);
    }else{
            help();
    }
    return (EXIT_SUCCESS);
}
    




/* 
 * Name: void help(void)
 * Desc: display contents of help
 * Args: void- no input
 *       void- no output
 */
void help(){
    printf("Usage: \n");
    printf("     P3.exe /?                                           ...run the help\n");
    printf("     P3.exe /h                                           ...run the help\n");    
    printf("     P3.exe /Circle /i                                   ...Circle_3D 1D\n");    
    printf("     P3.exe /Annulus /i                                  ...Annulus_3D 1D\n");
    printf("     P3.exe /RF /i                                       ...Rectangle_Filled_3D\n");
    printf("     P3.exe /RH /i                                       ...Rectangle_Hollow_3D\n");
}

/*
* Name: <circle_3D_v1>
* Desc: <taking user input and generating the, edge face, area face, area inner, area outer, and volume>
* Args: <Double Radius and Double Lengths>
*/
int circle_3D_v2(double radius, double length) {
    printf("Calling circle_3D_v2...\n");
    

    double edge_face;
    double area_face;
    double area_inner;
    double area_outer;
    double volume;
    
    edge_face = 0.0;
    area_face = 0.0;
    area_inner = 0.0;
    area_outer = 0.0;
    volume = 0.0;
    

    
    edge_face = 2 *(2 *M_PI * radius);
    area_face = 2 * ( M_PI * pow(radius,2.0));
    area_outer = ( 2*M_PI * radius) * length;
    area_inner = 0;
    volume = ( M_PI * pow( radius,2.0))*length;
    
    // Displaying results
    
    printf("Name                            Value\n");
     printf("===============================================\n");
     printf("radius (in):                    %.4f\n", radius);
     printf("length (in):                    %.4f\n", length);
     printf("edge_face (in):                 %.4f\n", edge_face);
     printf("area_face (in):                 %.4f\n", area_face);
     printf("area_outer (in):                %.4f\n", area_outer);
     printf("area_inner (in:                 %.4f\n", area_inner);
     printf("volume (in^3):                  %.4f\n", volume);
     printf("===============================================\n");
    
    
    return (EXIT_SUCCESS);    
}

/*
* Name: <annulus_3D_v1>
* Desc: <taking user input and generating the, edge face, area face, area inner, area outer, and volume>
* Args: <Takes in all doubles for an outer radius, inner radius, and a length>
*/
int annulus_3D_v2(double radius_outer, double radius_inner, double length) {
        printf("Calling annulus_3D_v2...\n");
    double edge_face;
    double area_face;
    double area_inner;
    double area_outer;
    double volume;
    
    edge_face = 0.0;
    area_face = 0.0;
    area_inner = 0.0;
    area_outer = 0.0;
    volume = 0.0;
    

    
    edge_face = 2 *(2 *M_PI * radius_outer) + 2 *(2 *M_PI * radius_inner);
    area_face = 2 * ( M_PI * pow(radius_outer,2.0))- 2 * ( M_PI * pow(radius_inner,2.0));
    area_outer = ( 2*M_PI * radius_outer)* length;
    area_inner = ( 2*M_PI * radius_inner)* length;
    volume = ( M_PI * pow( radius_outer,2.0)*length -( M_PI * pow( radius_inner,2.0))*length);
    
    // Displaying results
    
    printf("Name                            Value\n");
     printf("===============================================\n");
     printf("radius (outer):                 %.4f\n", radius_outer);
     printf("radius (inner):                 %.4f\n", radius_inner);
     printf("length (in):                    %.4f\n", length);
     printf("edge_face (in):                 %.4f\n", edge_face);
     printf("area_face (in):                 %.4f\n", area_face);
     printf("area_outer (in):                %.4f\n", area_outer);
     printf("area_inner (in:                 %.4f\n", area_inner);
     printf("volume (in^3):                  %.4f\n", volume);
     printf("===============================================\n");
    
    
    
}
/*
* Name: <rectangle_filled_3D_v2>
* Desc: <taking user input and generating the, edge face, area face, area inner, area outer, and volume>
* Args: <All type double for a base, height, and length>
*/
int rectangle_filled_3D_v2(double base, double height, double length) {
    printf("Calling rectangle_filled_3D_v2...\n");

    
    double edge_face;
    double area_face;
    double area_inner;
    double area_outer;
    double volume;

    edge_face = 0.0;
    area_face = 0.0;
    area_inner = 0.0;
    area_outer = 0.0;
    volume = 0.0;
    

    
    edge_face = length + height;
    area_face = height * height;
    area_outer = 3*height*length;
    area_inner = 0;
    volume = length * base * height;
    
    // Displaying results
    
    printf("Name                            Value\n");
     printf("===============================================\n");
     printf("base (in):                      %.4f\n", base);
     printf("height (in):                    %.4f\n", height);
     printf("length (in):                    %.4f\n", length);
     printf("edge_face (in):                 %.4f\n", edge_face);
     printf("area_face (in):                 %.4f\n", area_face);
     printf("area_outer (in):                %.4f\n", area_outer);
     printf("area_inner (in:                 %.4f\n", area_inner);
     printf("volume (in^3):                  %.4f\n", volume);
     printf("===============================================\n");
    
    return (EXIT_SUCCESS);    
}

/*
* Name: <rectangle_hollow_3D_v2>
* Desc: <taking user input and generating the, edge face, area face, area inner, area outer, and volume>
* Args: <All type doubles for an outer base, outer height, inner base, inner height, and length>
*/
int rectangle_hollow_3D_v2(double base_outer, double height_outer, double base_inner, double height_inner, double length) {
    printf("Calling rectangle_hollow_3D_v1...\n");  
    double edge_face;
    double area_face;
    double area_inner;
    double area_outer;
    double volume;
    

    edge_face = 0.0;
    area_face = 0.0;
    area_inner = 0.0;
    area_outer = 0.0;
    volume = 0.0;
    

    
    edge_face = length * height_outer + base_outer * base_outer;
    area_face = base_outer + base_inner;
    area_outer = 3*height_outer*length;
    area_inner = 3*height_inner*length;
    volume = (length * base_outer * height_outer) - (length * base_inner * height_inner) ;
    
    // Displaying results
    
    printf("Name                            Value\n");
     printf("===============================================\n");
     printf("base_outer (in):                %.4f\n", base_outer);
     printf("height_outer (in):              %.4f\n", height_outer);
     printf("base_inner (in):                %.4f\n", base_inner);
     printf("height_inner (in):              %.4f\n", height_inner);
     printf("length (in):                    %.4f\n", length);
     printf("edge_face (in):                 %.4f\n", edge_face);
     printf("area_face (in):                 %.4f\n", area_face);
     printf("area_outer (in):                %.4f\n", area_outer);
     printf("area_inner (in:                 %.4f\n", area_inner);
     printf("volume (in^3):                  %.4f\n", volume);
     printf("===============================================\n");
    return (EXIT_SUCCESS);    
}


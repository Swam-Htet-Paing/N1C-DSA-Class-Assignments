#include<stdio.h>
#include<conio.h>

int g_users = 0;
int g_user_login_check = -1;

struct User_info_DB{
    int u_id;
    char u_email[30];
    char u_name[30];
    char u_address[50];
    char u_pass[20];
    int u_postalcode;
    int u_ph_number;
};

struct User_info_DB user[5];

void Register(){
    int i = g_users;

    if (i>= 5){
        printf("Sorry, the system only allows 5 users for maximum.");
    }

    else{
        printf("Enter your name : ");
        scanf(" %[^\n]",&user[i].u_name);
        printf("Enter your email address : ");
        scanf(" %[^\n]",&user[i].u_email);
        printf("Enter your address : ");
        scanf(" %[^\n]",&user[i].u_address);
        printf("Enter your cellphone number : ");
        scanf(" %[^\n]",&user[i].u_ph_number);
        printf("Enter your postal code : ");
        scanf(" %[^\n]",&user[i].u_postalcode);
        printf("Enter your password : ");
        scanf(" %[^\n]",&user[i].u_pass);

        user[i].u_id = g_users;

        g_users++;

    }
}

int get_arr_len(char arr[30]){
    int i = 0;
    int size = 0;
    for (int i=0; i<=30; i++){
        if(arr[i]= '\0')
            break;
        size++;
    }
    return size;
}

int check_2arrays(char first_arr[30], char second_arr[30]){
    int arr1_size = get_arr_len(first_arr);
    int arr2_size = get_arr_len(second_arr);
    int correct_time = 0;

    if (arr1_size == arr2_size){
        for (int i=0; i<=arr1_size; i++){
            if(first_arr[i] == second_arr[i])
                correct_time++;
        }
    }

    if (arr1_size == correct_time)
        return 1;
    else
        return 0;
}

void Login(){

    char l_email[30];
    char l_pass[20];
    
    printf("Enter your email address : ");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password : ");
    scanf(" %[^\n]",&l_pass);

    for (int i=0; i<=g_users; i++){
        int email_check = check_2arrays(l_email, user[i].u_email);
        if (email_check == 1){
            int pass_check = check_2arrays(l_email, user[i].u_pass);
            if (pass_check == 1){
                g_user_login_check = user[i].u_id;
                break;
            }
        }
    }

    if (g_user_login_check != -1){
        printf("Login successful, welcome back %s", user[g_user_login_check].u_name);
        user_feed();
    }

    else
        printf("Incorrect email or password, please try again.");
    
}

menu(){
    while (1){
        int input = 0;
        printf("Press 1 to login, 2 to register or 3 to exit : \n");
        scanf("%d",&input);
        if (input == 1)
            Login();
        else if (input == 2)
            Register();
        else if (input == 3)
            exit(1);
        else
            printf("Invalid input, please enter available options (1-3)\n");
    }
}

void user_feed(){

    while (1){
        int choice = 0;
        printf("Press 1 to read today's article.\n Press 2 to logout : \n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Hi");
        }
        else if (choice == 2){
            printf("Logging out...\n");
            break;
        }

        else{
            printf("Invalid input, please type either 1 or 2.");
        }
    }

    //menu();
}


void copy_arr_content(char arr1[50], char arr2[50]){
    int length = get_arr_len(arr1);
    for(int i=0; i<=length; i++)
        arr1[i] = arr2[i];
}

int main(){
    menu();
    getch();
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_STRING_LEN 256
#define FILENAME "todo.txt"

typedef struct
{
    char string[MAX_STRING_LEN];
    int complete;
    int priority;      // 0 = Low, 1 = Medium, 2 = High;
    char deadline[20]; // formate: YYYY-MM-DD;
} Task;

const char *priorityToString(int p)
{
    switch (p)
    {
    case 2:
        return "High";
    case 1:
        return "Medium";
    case 0:
    default:
        return "Low";
    }
}

Task tasks[MAX_TASKS];
int totalCount = 0;

void loadTasks()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("There is no prior list existed, creating new list.\n");
        return;
    }

    totalCount = 0;
    while (totalCount < MAX_TASKS && fscanf(file, "%d,%d,%[^,],%[^\n]\n", &tasks[totalCount].complete, &tasks[totalCount].priority, tasks[totalCount].deadline, tasks[totalCount].string) == 4)
    {
        totalCount++;
    }
    // while (totalCount < MAX_TASKS && fscanf(file, "%d,%d: %[^\n]\n", &tasks[totalCount].complete, &tasks[totalCount].priority, tasks[totalCount].string) == 3)
    // {
    //     totalCount++;
    // }

    printf("--------------TO-DO List loaded successfully !------------------");
    fclose(file);
}

void saveTasks()
{
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL)
    {
        printf("File name %s could not be opened!\n", FILENAME);
        return;
    }

    // for (int i = 0; i < totalCount; i++)
    // {
    //     fprintf(file, "%d,%d %s\n", tasks[i].complete, tasks[i].priority, tasks[i].string);
    // }

    for (int i = 0; i < totalCount; i++)
    {
        fprintf(file, "%d,%d,%s,%s\n", tasks[i].complete, tasks[i].priority, tasks[i].deadline, tasks[i].string);
    }

    printf("Save successfully!\n");
}

void addTasks()
{
    if (totalCount >= MAX_TASKS)
    {
        printf("Error: To-Do list is full! Cannot add more tasks.\n");
        return;
    }

    printf("Enter the task content:-");

    char content[MAX_STRING_LEN];

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    if (fgets(content, MAX_STRING_LEN, stdin) != NULL)
    {
        content[strcspn(content, "\n")] = 0;

        strcpy(tasks[totalCount].string, content);
        tasks[totalCount].complete = 0;

        int priority;
        do
        {
            printf("Enter priority (0 = Low, 1 = Medium, 2 = High): ");
        } while (scanf("%d", &priority) != 1 || priority < 0 || priority > 2);
        tasks[totalCount].priority = priority;

        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Enter deadline (YYYY-MM-DD): ");
        fgets(tasks[totalCount].deadline, sizeof(tasks[totalCount].deadline), stdin);
        tasks[totalCount].deadline[strcspn(tasks[totalCount].deadline, "\n")] = 0;

        totalCount++;
        saveTasks(); // Auto save here
        printf("Task added successfully.\n");
    }
    else
    {
        printf("Error reading input.\n");
    }
}

int compareTasks(const void *a, const void *b)
{
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    if (t1->priority != t2->priority)
        return t2->priority - t1->priority;    // Higher priority first
    return strcmp(t1->deadline, t2->deadline); // Earlier deadline first
}

void viewTasks()
{
    if (totalCount == 0)
    {
        printf("The TODO list is empty!\n");
        return;
    }

    qsort(tasks, totalCount, sizeof(Task), compareTasks);

    printf("-------Todo List----------\n");
    for (int i = 0; i < totalCount; i++)
    {
        printf("%d. [%c] (%s) [Due: %s] %s\n", i + 1, tasks[i].complete ? 'X' : ' ', priorityToString(tasks[i].priority), tasks[i].deadline, tasks[i].string);
    }
    printf("--------------------------\n");
}

void markTaskComplete()
{
    if (totalCount == 0)
    {
        printf("TODO list is empty nothing to mark.\n");
    }

    viewTasks();
    int number;
    printf("Enter the number of the task to mark as complete: ");
    if (scanf("%d", &number) != 1 || number < 1 || number > totalCount)
    {
        printf("Invalid input. Please enter a valid input!\n");

        while (getchar() != '\n')
            ;
        return;
    }
    tasks[number - 1].complete = 1;
    saveTasks(); // Auto save here
    printf("The task number : %d with task : %s \n has been marked complete.\n", number, tasks[number - 1].string);
}

void deleteTasks()
{
    if (totalCount == 0)
    {
        printf("TODO list is empty nothing to mark.\n");
    }

    viewTasks();
    int number;
    printf("Enter the number of the task to delete: ");
    if (scanf("%d", &number) != 1 || number < 1 || number > totalCount)
    {
        printf("Invalid input. Please enter a valid input!\n");

        while (getchar() != '\n')
            ;
        return;
    }
    printf("Deleting task %s\n", tasks[number - 1].string);
    for (int i = number - 1; i < totalCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    totalCount--;
    printf("Task deleted successfully.\n");
    saveTasks(); // Auto save here
}

void clearCompletedTasks()
{
    int i = 0;
    while (i < totalCount)
    {
        if (tasks[i].complete)
        {
            for (int j = i; j < totalCount - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }
            totalCount--;
        }
        else
        {
            i++;
        }
    }
    printf("All completed tasks deleted!\n");
    saveTasks(); // Auto save here
}

void editTasks()
{
    if (totalCount == 0)
    {
        printf("TODO list is empty.\n");
        return;
    }

    viewTasks();
    int number;
    printf("Enter Task number to edit.\n");
    if (scanf("%d", &number) != 1 || number < 1 || number > totalCount)
    {
        printf("Invalid Input.\n");
        while (getchar() != '\n')
        {
            return;
        }
    }

    printf("Enter new Task content: \n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(tasks[number - 1].string, MAX_STRING_LEN, stdin);
    tasks[number - 1].string[strcspn(tasks[number - 1].string, '\n')] = 0;

    int priority;
    do
    {
        printf("Enter new Priority ( 0 = 'Low', 1 = 'Medium', 2 = 'High' ): \n");
    } while (scanf("%d", &priority) != 1 || priority < 0 || priority > 2);

    tasks[number - 1].priority = priority;
    printf("Task updated successfully.\n");
    saveTasks(); // Auto save here
}

void searchTasks()
{
    if (totalCount == 0)
    {
        printf("TODO list is empty.\n");
        return;
    }

    printf("Enter keyword to search: ");
    char keyword[MAX_STRING_LEN];
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(keyword, MAX_STRING_LEN, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    printf("-----Search Result------\n");
    for (int i = 0; i < totalCount; i++)
    {
        if (strstr(tasks[i].string, keyword))
        {
            printf("%d. [%c] (%s) %s\n", i + 1, tasks[i].complete ? 'X' : ' ', priorityToString(tasks[i].priority), tasks[i].string);
        }
    }
    printf("--------------------\n");
}

void editDeadLine()
{
    if (totalCount == 0)
    {
        printf("TODO list in empty.\n");
        return;
    }

    viewTasks();
    int number;
    printf("Enter task number to edit deadline : \n");
    if (scanf("%d", &number) != 1 || number < 1 || number > totalCount)
    {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    while (getchar() != '\n')
        ;
    fgets(tasks[number - 1].deadline, sizeof(tasks[number - 1].deadline), stdin);
    tasks[number - 1].deadline[strcspn(tasks[number - 1].deadline, "\n")] = 0;
    saveTasks();
    printf("DeadLine updated successfully!\n");
}

void filterOverdueTasks()
{
    if (totalCount == 0)
    {
        printf("TODO list is empty.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    char today[11];
    strftime(today, sizeof(today), "%Y-%m-%d", now);

    printf("----- Overdue Tasks ------\n");
    int found = 0;
    for (int i = 0; i < totalCount; i++)
    {
        if (!tasks[i].complete && strcmp(tasks[i].deadline, today) < 0)
        {
            printf("%d. [%c] (%s) [Due: %s] %s\n", i + 1, tasks[i].complete ? 'X' : ' ', priorityToString(tasks[i].priority), tasks[i].deadline, tasks[i].string);
            found = 1;
        }
    }
    if (!found)
        printf("No overdue tasks.\n");
    printf("--------------------------\n");
}

void displayMenu()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("\n--- To-Do List Menu ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Task Complete\n");
    printf("4. Delete Task\n");
    printf("5. Save Tasks\n");
    printf("6. Load Tasks\n");
    printf("7. Clear Completed Tasks\n");
    printf("8. Edit Task\n");
    printf("9. Search Task\n");
    printf("10.Edit Deadline\n");
    printf("11.Filter Overdue Tasks\n");
    printf("12. Exit\n");
    printf("Enter your choice: \n");
}

int main()
{
    loadTasks();
    int choice;
    do
    {
        displayMenu(); // Show menu options
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer to prevent infinite loop on bad input
            while (getchar() != '\n')
                ;
            continue; // Skip to next iteration of the loop
        }

        switch (choice)
        {
        case 1:
            addTasks();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markTaskComplete();
            break;
        case 4:
            deleteTasks();
            break;
        case 5:
            saveTasks();
            break;
        case 6:
            loadTasks();
            break;
        case 7:
            clearCompletedTasks();
            break;
        case 8:
            editTasks();
            break;
        case 9:
            searchTasks();
            break;
        case 10:
            editDeadLine();
            break;
        case 11:
            filterOverdueTasks();
            break;
        case 12:
            printf("Exiting To-Do List. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        printf("\nPress Enter to continue...");
        while (getchar() != '\n')
            ;
    } while (choice != 12);
    return 0;
}
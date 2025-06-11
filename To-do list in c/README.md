
## 📋 To-Do List Application (C Language)

A command-line **To-Do List Manager** written in **C**, supporting task creation, deadlines, priority sorting, task editing, filtering overdue tasks, and file persistence using `todo.txt`.

---

### 🚀 Features

* ✅ Add new tasks with:

  * Priority (Low, Medium, High)
  * Deadline (`YYYY-MM-DD` format)
* 📄 View all tasks sorted by:

  * Priority (High → Low)
  * Deadline (Earlier → Later)
* 🗂️ Edit or delete tasks
* ✔️ Mark tasks as complete
* 🔍 Search tasks by keyword
* 🗓️ Edit deadlines
* 🧹 Clear all completed tasks
* ⚠️ Filter and display overdue tasks
* 💾 Tasks are saved in a file `todo.txt` for persistence

---

### 💻 How to Compile & Run

#### ✅ Compile

Using GCC:

```bash
gcc todo.c -o todo
```

#### ▶️ Run

```bash
./todo
```

---

### 📁 File Format (`todo.txt`)

Each task is stored in this format:

```
<complete>,<priority>,<deadline>,<task description>
```

**Example:**

```
0,2,2025-06-15,Submit final project report
1,1,2025-06-10,Buy groceries
```

---

### 🧠 Code Structure

* `Task` struct stores:

  * `string`: task content
  * `priority`: 0 (Low), 1 (Medium), 2 (High)
  * `complete`: 0 or 1
  * `deadline`: deadline in `YYYY-MM-DD`
* All tasks are stored in an array of max 100 tasks
* File operations handled via `loadTasks()` and `saveTasks()`

---

### 📦 Dependencies

* Standard C Libraries: `stdio.h`, `stdlib.h`, `string.h`, `time.h`

No external libraries are required.

---

### 🎯 Future Improvements (Ideas)

* ✅ Date format validation
* ✅ Show number of deleted tasks when clearing
* ☑️ Add colored output for priority levels (using ANSI escape codes)
* ⌛ Countdown or notification for upcoming deadlines
* 🌐 Port to GUI (using GTK or C++ Qt)
* 📱 Port to mobile app

---

### 🙌 Author

**Sparsh Singh**
*B.Tech CSE student, Central University of Rajasthan*

> Passionate about building useful command-line tools & learning system-level programming.



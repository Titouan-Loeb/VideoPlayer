# Video Player

## How to run
* After cloning the repository, open **the VideoPlayer.sln** file in Visual Studio and run the project in both Debug and Release configurations (make sure you are in **x64**), it will create the necessary folders for the next step.
* Copy the content of the folder **copyTo-x64-Debug** into the the folder **x64\Debug**.
* Copy the content of the folder **copyTo-x64-Release** into the the folder **x64\Release**.

#### Now you should be able to run the project in Visual Studio!

## Challenge report - What happend to me during this challenge
### During this project I had to face different issues.

* First of all I am not used to Visual Studio and coding on Windows, I am more used to Linux and Visual Studio Code.
* I don't know well any graphical library meant for UI in C++, but I still wanted try to use for the first time wxWidgets.
After some time I found myself stuck with this library. So I started from scratch again and I used the SFML library that I know much better, but this library is meant more for game deveolpment than UI development.
With this library it took me much more time to accomplish less, but I was much more confortable.

### What a managed to do
On monday afternoon, I started to use the SFML library, I made the architecture and I started to develop my firsts UI components. On Tuesday I was not able to work on this challenge so I continued on wednesday morning.

What I have so far is:
* A window that you can switch from full screen to small screen.
* A progress bar that moves with time, you can select a moment on the progress bar, and when it is full, it restarts at the beginning.
* A Play/Pause button that affect the time and the growth of the progess bar.

So I didn't managed to read and play a video yet, natively you cannot read videos with the SFML library but there is a free access project made with SFML that can do it for you. I intended to use it but I didn't have to time to do it yet.

## Architecture
### Class diagram
You can find a class diagram of this project [here](https://miro.com/app/board/uXjVOKEijU0=/?invite_link_id=315472840092).

### Explanation of the architecture

In my **Window** class I can handle basic events, it contains an array of **IScenes** which is an interface for the different possible scenes. In reality this challenge requires only one scene, but I made an interface because there could be much more scenes, For instance:
* 1st scene: Showing a list of video that you can whatch.
* 2sd scene: The video player.

So this interface was made to let the possibility to add more features to this challenge. Here, my only scene is the **VideoVue** class.

Then I created an abstract class (**AGUI**) for UI components, basicaly this is a class for all the different components that I will display, each scene should have an array of **AGUI**.
3 classes are inheriting from the **AGUI** class:
* **CheckBox** (for the play/stop and full-screen/small-screen buttons)
* **ProgressBar**
* **Video**

I wanted to add other components such as button, image, text... But I was running out of time.

## Conclusion

As expected this challenge is not finished at all but I'm intend to continue it, I will probably push other features this week-end.

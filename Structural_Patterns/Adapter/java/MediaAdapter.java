/**
 *  @file       MediaAdapter.java
 *  @brief
 *
 */


import MediaPlayer.*;
import VlcPlayer.*;
import Mp4Player.*;


public class MediaAdapter implements MediaPlayer
{
    AdvancedMediaPlayer advancedMusicPlayer;

    public MediaAdapter(String audioType)
    {
        if (audioType.equalsIgnoreCase("vls"))
        {
            advancedMusicPlayer = new VlcPlayer();
        }
        else if (audioType.equalsIgnoreCase("mp4"))
        {
            advancedMusicPlayer = new Mp4Player();
        }
    }

    @override
    public void play(String audioType, String fileName)
    {
        if (audioType.equalsIgnoreCase("vlc"))
        {
            advancedMusicPlayer.playVlc(fileName);
        }
        else if (audioType.equalsIgnoreCase("mp4"))
        {
            advancedMusicPlayer.playMp4(fileName);
        }
    }
}

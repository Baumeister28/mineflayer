#ifndef CHUNK_H
#define CHUNK_H

#include <QtGlobal>

#include <QVector>
#include <QSharedPointer>
#include <QHash>

#include "Int3D.h"

class Chunk {
public:

    enum ItemType {
        NoItem=-1,
        Air=0x00,
        Stone=0x01,
        Grass=0x02,
        Dirt=0x03,
        Cobblestone=0x04,
        WoodenPlank=0x05,
        Sapling=0x06,
        Bedrock=0x07,
        Water=0x08,
        StationaryWater=0x09,
        Lava=0x0A,
        StationaryLava=0x0B,
        Sand=0x0C,
        Gravel=0x0D,
        GoldOre=0x0E,
        IronOre=0x0F,
        CoalOre=0x10,
        Wood=0x11,
        Leaves=0x12,
        Sponge=0x13,
        Glass=0x14,
        LapisLazuliOre=0x15,
        LapisLazuliBlock=0x16,
        Dispenser=0x17,
        Sandstone=0x18,
        NoteBlock=0x19,
        Wool=0x23,
        YellowFlower=0x25,
        RedRose=0x26,
        BrownMushroom=0x27,
        RedMushroom=0x28,
        GoldBlock=0x29,
        IronBlock=0x2A,
        DoubleStoneSlab=0x2B,
        StoneSlab=0x2C,
        Brick=0x2D,
        TNT=0x2E,
        Bookshelf=0x2F,
        MossStone=0x30,
        Obsidian=0x31,
        Torch=0x32,
        Fire=0x33,
        MonsterSpawner=0x34,
        WoodenStairs=0x35,
        Chest=0x36,
        RedstoneWire_placed=0x37,
        DiamondOre=0x38,
        DiamondBlock=0x39,
        Workbench=0x3A,
        Crops=0x3B,
        Farmland=0x3C,
        Furnace=0x3D,
        BurningFurnace=0x3E,
        SignPost_placed=0x3F,
        WoodenDoor_placed=0x40,
        Ladder=0x41,
        MinecartTracks=0x42,
        CobblestoneStairs=0x43,
        WallSign_placed=0x44,
        Lever=0x45,
        StonePressurePlate=0x46,
        IronDoor_placed=0x47,
        WoodenPressurePlate=0x48,
        RedstoneOre=0x49,
        GlowingRedstoneOre=0x4A,
        RedstoneTorchOff_placed=0x4B,
        RedstoneTorchOn=0x4C,
        StoneButton=0x4D,
        Snow=0x4E,
        Ice=0x4F,
        SnowBlock=0x50,
        Cactus=0x51,
        Clay=0x52,
        SugarCane_place=0x53,
        Jukebox=0x54,
        Fence=0x55,
        Pumpkin=0x56,
        Netherrack=0x57,
        SoulSand=0x58,
        Glowstone=0x59,
        Portal=0x5A,
        JackOLantern=0x5B,
        CakeBlock=0x5C,

        IronShovel=0x100,
        IronPickaxe=0x101,
        IronAxe=0x102,
        FlintAndSteel=0x103,
        Apple=0x104,
        Bow=0x105,
        Arrow=0x106,
        Coal=0x107,
        Diamond=0x108,
        IronIngot=0x109,
        GoldIngot=0x10A,
        IronSword=0x10B,
        WoodenSword=0x10C,
        WoodenShovel=0x10D,
        WoodenPickaxe=0x10E,
        WoodenAxe=0x10F,
        StoneSword=0x110,
        StoneShovel=0x111,
        StonePickaxe=0x112,
        StoneAxe=0x113,
        DiamondSword=0x114,
        DiamondShovel=0x115,
        DiamondPickaxe=0x116,
        DiamondAxe=0x117,
        Stick=0x118,
        Bowl=0x119,
        MushroomSoup=0x11A,
        GoldSword=0x11B,
        GoldShovel=0x11C,
        GoldPickaxe=0x11D,
        GoldAxe=0x11E,
        String=0x11F,
        Feather=0x120,
        Sulphur=0x121,
        WoodenHoe=0x122,
        StoneHoe=0x123,
        IronHoe=0x124,
        DiamondHoe=0x125,
        GoldHoe=0x126,
        Seeds=0x127,
        Wheat=0x128,
        Bread=0x129,
        LeatherHelmet=0x12A,
        LeatherChestplate=0x12B,
        LeatherLeggings=0x12C,
        LeatherBoots=0x12D,
        ChainmailHelmet=0x12E,
        ChainmailChestplate=0x12F,
        ChainmailLeggings=0x130,
        ChainmailBoots=0x131,
        IronHelmet=0x132,
        IronChestplate=0x133,
        IronLeggings=0x134,
        IronBoots=0x135,
        DiamondHelmet=0x136,
        DiamondChestplate=0x137,
        DiamondLeggings=0x138,
        DiamondBoots=0x139,
        GoldHelmet=0x13A,
        GoldChestplate=0x13B,
        GoldLeggings=0x13C,
        GoldBoots=0x13D,
        Flint=0x13E,
        RawPorkchop=0x13F,
        CookedPorkchop=0x140,
        Paintings=0x141,
        GoldenApple=0x142,
        Sign=0x143,
        WoodenDoor=0x144,
        Bucket=0x145,
        WaterBucket=0x146,
        LavaBucket=0x147,
        Minecart=0x148,
        Saddle=0x149,
        IronDoor=0x14A,
        Redstone=0x14B,
        Snowball=0x14C,
        Boat=0x14D,
        Leather=0x14E,
        Milk=0x14F,
        ClayBrick=0x150,
        ClayBalls=0x151,
        SugarCane=0x152,
        Paper=0x153,
        Book=0x154,
        Slimeball=0x155,
        StorageMinecart=0x156,
        PoweredMinecart=0x157,
        Egg=0x158,
        Compass=0x159,
        FishingRod=0x15A,
        Clock=0x15B,
        GlowstoneDust=0x15C,
        RawFish=0x15D,
        CookedFish=0x15E,
        InkSac=0x15F,
        Bone=0x160,
        Sugar=0x161,
        Cake=0x162,
        GoldMusicDisc=0x8D0,
        GreenMusicDisc=0x8D1,
    };

    struct Block {
        ItemType type;
        int metadata;
        int light;
        int sky_light;
    };

public:
    Chunk(const Int3D & pos, const Int3D & size);

    Block getBlock(const Int3D & coord) const;
    void setBlock(const Int3D & coord, const Block & value);

    Int3D position() const { return m_pos; }
    Int3D size() const { return m_size; }

private:
    Int3D m_pos;
    Int3D m_size;
    QVector<Block> m_blocks;

private:
    int indexOf(const Int3D & coord) const;
};

uint qHash(const Int3D & coord);

#endif // CHUNK_H

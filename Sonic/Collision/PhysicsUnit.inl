namespace Sonic
{
    inline void CPhysicsUnit::AddProperty(int id, int value)
    {
        struct
        {
            int value;
            int buffer;
        } data;
        data.value = value;
        AddProperty(id, (uint64_t*)&data);
    }

    inline void CPhysicsUnit::AddBoolProperty(int hashedName, int id)
    {
        if (!HasProperty(hashedName))
            return;

        uint64_t data = 0;
        GetProperty(&data, hashedName);

        data = data != 0;
        AddProperty(id, &data);
    }

    inline bool CPhysicsUnit::GetBoolProperty(int id)
    {
        if (!HasProperty(id))
            return false;

        uint64_t data = 0;
        GetProperty(&data, id);

        return data != 0;
    }
}